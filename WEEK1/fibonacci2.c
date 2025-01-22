#include<stdio.h>

long fibonacci(long n){

	if(n == 0 || n == 1){

		return n;
	}

	long result = fibonacci(n - 1) + fibonacci(n-2);

	return result;

}


int main(){

	long n;

	printf("Enter a number : ");
	scanf("%ld", &n);

	printf("The fibonacci numbers are : ");

	for (long i = 1; i <= n; i++) {

		printf("%ld ", fibonacci(i));

	}

	return 0;
}

