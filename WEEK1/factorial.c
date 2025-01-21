#include<stdio.h>

long factorial(int n){

	if(n == 0 || n == 1){

		return 1 ;
	}

	return factorial(n -1)*n;

}


int main(){

	int n;

	printf("Enter a number : ");
	scanf("%d", &n);

	long ans = factorial(n);

	printf("The factorial of %d is: %ld",n,ans);

	return 0;
}
