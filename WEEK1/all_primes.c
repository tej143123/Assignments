#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool findPrimes(int n){

	int cnt = 0;

	for(int i=1;i<=sqrt(n);i++){

		if((n % i) == 0){

			cnt++;

			if((n / i) != i){

				cnt++;

			}
		}
	}

	if(cnt == 2) return true;

	return false;

}


int main(){

	int n;

	printf("Enter a number : ");
	scanf("%d", &n);

	printf("The prime numbers till %d are : ", n);


	for(int i=2;i<=n;i++){

		if(findPrimes(i)){

			printf("%d ", i);

		}

	}

	return 0;

}
