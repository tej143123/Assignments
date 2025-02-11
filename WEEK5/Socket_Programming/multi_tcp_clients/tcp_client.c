#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void *receive_messages(void *sock_desc) {
	int sock = *(int*)sock_desc;
	char buffer[BUFFER_SIZE];

	while (1) {
		memset(buffer, 0, BUFFER_SIZE);
		int bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0);
		if (bytes_received <= 0) {
			printf("Server disconnected.\n");
			close(sock);
			exit(0);
		}
		buffer[bytes_received] = '\0';
		printf("\nServer: %s", buffer);
		printf("\nYou: ");
		fflush(stdout); // Ensure prompt stays at the right place
	}
	return NULL;
}

int main() {
	int sock;
	struct sockaddr_in server_addr;
	char buffer[BUFFER_SIZE];

	// 1. Create socket
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1) {
		perror("Socket creation failed");
		exit(EXIT_FAILURE);
	}

	// 2. Set up server address
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	printf("Enter Server IP: ");
	char server_ip[INET_ADDRSTRLEN];
	scanf("%s", server_ip);
	getchar(); // Remove newline from input buffer

	if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
		perror("Invalid server address");
		exit(EXIT_FAILURE);
	}

	// 3. Connect to server
	if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
		perror("Connection failed");
		exit(EXIT_FAILURE);
	}
	printf("Connected to server!\n");

	// 4. Start thread for receiving messages
	pthread_t thread;
	pthread_create(&thread, NULL, receive_messages, (void*)&sock);

	// 5. Handle sending messages
	while (1) {
		printf("You: ");
		memset(buffer, 0, BUFFER_SIZE);
		fgets(buffer, BUFFER_SIZE, stdin);
		send(sock, buffer, strlen(buffer), 0);
	}

	close(sock);
	return 0;
}

