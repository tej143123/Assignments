#include<stdio.h>

// Function to calculate the sum of proper divisors of a number
long isPerfect(long a) {
	int i = 1; 
	int sum = 0; 

	// Loop through numbers up to half of 'a' to find divisors
	while (i <= a / 2) {
		if (a % i == 0) { 
			sum += i; // Add the divisor to the sum
		}
		i++;
	}

	return sum; // Returns the sum of proper divisors
}

int main() {
	long a;

	// Prompt the user to enter a number and read the input
	printf("Enter a number : ");
	scanf("%ld", &a);

	// Calculate the sum of divisors using isPerfect function
	long ans = isPerfect(a);

	// Check if the input number is a perfect number
	if (ans == a) {
		printf("\n%ld is a perfect number ", a);
	} else {
		printf("\n%ld is not a perfect number ", a);
	}

	return 0; 
}

