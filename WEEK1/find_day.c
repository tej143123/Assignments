#include <stdio.h>

int getMonthValue(int month) {

	switch(month)	{
		case 1: return 0;  
		case 2: return 3; 
		case 3: return 3;
		case 4: return 6;
		case 5: return 1; 
		case 6: return 4;
		case 7: return 6;
		case 8: return 2; 
		case 9: return 5;
		case 10: return 0;
		case 11: return 3;
		case 12: return 5;
		default: return -1;
	}
}

int getCenturyValue(int year) {

	if (year >= 1500 && year <= 1599) {
		return 0;
	} else if (year >= 1600 && year <= 1699) {
		return 6;
	} else if (year >= 1700 && year <= 1799) {
		return 4;
	} else if (year >= 1800 && year <= 1899) {
		return 2;
	} else if (year >= 1900 && year <= 1999) {
		return 0;
	} else if (year >= 2000 && year <= 2099) {
		return 6;
	}
	return -1;
}

void findDay(int day, int month, int year) {
	int centuryValue = getCenturyValue(year);
	int monthValue = getMonthValue(month);
	int lastTwoDigitsOfYear = year % 100;
	int result  = (lastTwoDigitsOfYear / 4);


	int total = lastTwoDigitsOfYear + result + day + monthValue + centuryValue;
	int remainder = total % 7;


	char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

	printf("The day is: %s\n", days[remainder]);
}

int main() {
	int day, month, year;


	printf("Enter the day : ");
	scanf("%d", &day);

	printf("Enter the month : ");
	scanf("%d", &month);

	printf("Enter the year: ");
	scanf("%d", &year);


	findDay(day, month, year);

	return 0;
}

