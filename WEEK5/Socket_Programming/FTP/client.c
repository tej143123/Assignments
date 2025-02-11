#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
	int sock;
	struct sockaddr_in server_addr;
	char buffer[BUFFER_SIZE];
	char filename[BUFFER_SIZE];
	char server_ip[INET_ADDRSTRLEN];

	// Get the server IP from the user
	printf("Enter Server IP: ");
	scanf("%s", server_ip);
	getchar();  // Clear newline character from input buffer

	// Create socket
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1) {
		perror("Socket creation failed");
		exit(EXIT_FAILURE);
	}

	// Set up server address
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
		perror("Invalid server address");
		exit(EXIT_FAILURE);
	}

	// Connect to the server
	if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
		perror("Connection failed");
		exit(EXIT_FAILURE);
	}
	printf("Connected to server at %s!\n", server_ip);

	// Get filename from user
	printf("Enter the filename to send: ");
	scanf("%s", filename);

	// Open file for reading
	FILE *file = fopen(filename, "rb");
	if (!file) {
		perror("File open failed");
		close(sock);
		exit(EXIT_FAILURE);
	}

	// Send filename to server
	send(sock, filename, strlen(filename) + 1, 0);

	// Send file data
	int bytes_read;
	while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
		send(sock, buffer, bytes_read, 0);
	}

	printf("File '%s' sent successfully to %s.\n", filename, server_ip);

	// Close everything
	fclose(file);
	close(sock);

	return 0;
}

