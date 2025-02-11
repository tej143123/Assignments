#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
	int server_fd, client_fd;
	struct sockaddr_in server_addr, client_addr;
	socklen_t addr_size = sizeof(client_addr);
	char buffer[BUFFER_SIZE];
	char filename[BUFFER_SIZE];

	// 1. Create socket
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd == -1) {
		perror("Socket creation failed");
		exit(EXIT_FAILURE);
	}

	// 2. Bind address to socket
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(PORT);

	if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
		perror("Bind failed");
		exit(EXIT_FAILURE);
	}

	// 3. Listen for connections
	if (listen(server_fd, 5) < 0) {
		perror("Listen failed");
		exit(EXIT_FAILURE);
	}

	printf("Server listening on port %d...\n", PORT);

	// 4. Accept client connection
	client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_size);
	if (client_fd < 0) {
		perror("Accept failed");
		exit(EXIT_FAILURE);
	}
	printf("Client connected.\n");

	// 5. Receive filename from client
	recv(client_fd, filename, BUFFER_SIZE, 0);
	printf("Receiving file: %s\n", filename);

	// 6. Open file for writing
	FILE *file = fopen(filename, "wb");
	if (!file) {
		perror("File open failed");
		exit(EXIT_FAILURE);
	}

	// 7. Receive file data
	int bytes_received;
	while ((bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0)) > 0) {
		fwrite(buffer, 1, bytes_received, file);
	}

	printf("File received successfully.\n");

	// 8. Close everything
	fclose(file);
	close(client_fd);
	close(server_fd);

	return 0;
}

