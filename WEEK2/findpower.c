#include<stdio.h>


float findPower(float x, float n){

	float ans = 1.0;

	for(int i=0;i<n;i++){
		ans *= x;
	}

	return ans;
}

int main(){

	float x, n;

	printf("Enter the value of x : ");
	scanf("%f", &x);

	printf("Enter the value of n : ");
	scanf("%f", &n);

	if(n < 0){
		float ans = 1/findPower(x, -(n));
		printf("The power(%.2f, %.2f) is : %.2f", x, n, ans);
	}
	else{
		float ans = findPower(x, n);
		printf("The power(%.2f, %.2f) is : %.2f", x, n, ans);
	}

	return 0;
}
