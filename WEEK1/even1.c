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

		printf("%d is a even number", n);
	}

	else{

		printf("%d is a odd number", n);
	}

	return 0;
}

