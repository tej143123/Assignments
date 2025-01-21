#include<stdio.h>
#define BITS 32
void print_bits(int n){

	for(int i=BITS - 1;i>=0;i--){

		int bit = (n >> i) & 1;

		printf("%u", bit);

	}
}

int main(){

	int n;

	printf("Enter a number (signed / unsigned) : ");
	scanf("%d", &n);

	printf("The Binary Representation of signed / unsigned value is : ");
	print_bits(n);

	if(n < 0){

		printf("\nThe binary representation is in 2's complement form ");

	}

	else{

		printf("\nThe %d is positive number ", n);

	}

	return 0;

}
