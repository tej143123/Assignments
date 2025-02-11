#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/socket.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int main() {
	int server_fd, new_socket, client_socket[MAX_CLIENTS] = {0};
	int max_sd, activity, sd, i;
	struct sockaddr_in address;
	socklen_t addrlen = sizeof(address);
	char buffer[BUFFER_SIZE];
	fd_set readfds;

	// 1. Create server socket
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd < 0) {
		perror("Socket failed");
		exit(EXIT_FAILURE);
	}

	// Set socket options
	int opt = 1;
	setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	// 2. Bind socket to IP/Port
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);
	if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
		perror("Bind failed");
		exit(EXIT_FAILURE);
	}

	// 3. Listen for connections
	if (listen(server_fd, MAX_CLIENTS) < 0) {
		perror("Listen failed");
		exit(EXIT_FAILURE);
	}
	printf("Server listening on port %d...\n", PORT);

	while (1) {
		// Clear socket set and add server socket
		FD_ZERO(&readfds);
		FD_SET(server_fd, &readfds);
		max_sd = server_fd;

		// Add client sockets to set
		for (i = 0; i < MAX_CLIENTS; i++) {
			sd = client_socket[i];
			if (sd > 0) FD_SET(sd, &readfds);
			if (sd > max_sd) max_sd = sd;
		}

		// 4. Wait for activity
		activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);
		if (activity < 0) {
			perror("Select error");
			continue;
		}

		// 5. Accept new connection
		if (FD_ISSET(server_fd, &readfds)) {
			new_socket = accept(server_fd, (struct sockaddr*)&address, &addrlen);
			if (new_socket < 0) {
				perror("Accept failed");
				continue;
			}

			printf("New connection: Socket %d, IP: %s, Port: %d\n",
					new_socket, inet_ntoa(address.sin_addr), ntohs(address.sin_port));

			// Add client socket
			for (i = 0; i < MAX_CLIENTS; i++) {
				if (client_socket[i] == 0) {
					client_socket[i] = new_socket;
					break;
				}
			}
		}

		// 6. Handle messages from clients
		for (i = 0; i < MAX_CLIENTS; i++) {
			sd = client_socket[i];
			if (FD_ISSET(sd, &readfds)) {
				int bytes_read = recv(sd, buffer, BUFFER_SIZE - 1, 0);
				if (bytes_read <= 0) {
					printf("Client on socket %d disconnected.\n", sd);
					close(sd);
					client_socket[i] = 0;
				} else {
					buffer[bytes_read] = '\0';  // Null terminate message
					printf("Client %d: %s", sd, buffer);

					// 7. Server inputs and sends a reply
					printf("Server: ");
					fgets(buffer, BUFFER_SIZE, stdin);
					send(sd, buffer, strlen(buffer), 0);
				}
			}
		}
	}

	close(server_fd);
	return 0;
}

