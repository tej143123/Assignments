#include<stdio.h>
#include<stdbool.h>

bool checkYear(int year){

	if((year % 4) == 0 &&((year % 400) == 0 || (year % 100) != 0)) return true;
	return false;
}


int main(){

	int year;

	printf("Enter the year : ");
	scanf("%d", &year);

	if(year < 0){
		printf("Please enter valid input");
	}

	else{
		bool ans = checkYear(year);

		if(ans){
			printf("The entered year %d is a leap year", year);
		}
		else{
			printf("The entered year %d is not a leap year", year);
		}
	}

	return 0;
}


