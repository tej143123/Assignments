#include<stdio.h>
#include<stdlib.h>

// Function to generate the first 'n' Fibonacci numbers
int* fibonacci(int n) {
	int* arr = (int*)malloc(n * sizeof(int)); // Allocate memory for the Fibonacci array

	int n1 = 0, n2 = 1;
	arr[0] = n1; // First Fibonacci number
	arr[1] = n2; // Second Fibonacci number

	// Generate remaining Fibonacci numbers
	for (int i = 2; i < n; i++) {
		int n3 = n1 + n2;
		arr[i] = n3;
		n1 = n2;
		n2 = n3;
	}

	return arr; // Return the array containing Fibonacci numbers
}

int main() {
	int n;

	// Prompt the user to enter the number of Fibonacci terms
	printf("Enter a number: ");
	scanf("%d", &n);

	int* ans = fibonacci(n); // Call the Fibonacci function

	// Display the generated Fibonacci sequence
	printf("The Fibonacci numbers of %d are: ", n);
	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}

	return 0; 
}

