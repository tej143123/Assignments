#include<stdio.h>

int findSquare(int x){

	int ans = 1;

	ans = x * x;

	return ans;

}


int main(){

	int n, sum = 0;

	printf("Enter the value of n : ");
	scanf("%d", &n);

	if(n < 0){
		printf("Please enter valid input");
	}

	else{
		printf("\nThe squares of first %d numbers are : ", n);

		for(int i=0;i<n;i++){

			int ans = findSquare(i);
			sum += ans;
			printf("\n%d", ans);

		}

		printf("\nThe sum of first %d squares is : %d", n, sum);
	}

	return 0;

}
