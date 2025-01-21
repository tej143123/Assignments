#include<stdio.h>
#define BITS 32

long find_circular_right_shift(int a, int n){

	long result1 = (a >> n);

	int numberOfShifts = (32 - n);

	long result2 = (a << numberOfShifts);

	long ans = result1 | result2 ;

	return ans;

}

long find_circular_left_shift(int a, int n){

	long result1 = (a << n);

	int numberOfShifts = (32 - n);

	long result2 = (a >> numberOfShifts);

	long ans = result1 | result2 ;

	return ans;

}


int main(){

	int a, n;

	printf("Enter a number : ");
	scanf("%d", &a);

	printf("\nEnter number of shifts : ");
	scanf("%d", &n);

	printf("\nThe circular right shift is : %ld", find_circular_right_shift(a, n));
	printf("\nThe circular right shift is : %ld", find_circular_left_shift(a, n));

	return 0;

}
