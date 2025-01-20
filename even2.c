#include<stdio.h>

int findEvenOrOdd(int n){

	return n & 1;
}

int main(){

	int n;

	printf("Enter a number : ");
	scanf("%d", &n);

	int ans = findEvenOrOdd(n);

	if(ans == 0){

		printf("\n%d is a even number", n);
	}

	else{

		printf("\n%d is a odd number", n);
	}

	if(n > 0){

		printf("\n%d is a positive number ", n);

	}

	else{

		printf("\n%d is a negative number ", n);

	}

	return 0;
}  
