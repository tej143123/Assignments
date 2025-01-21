#include<stdio.h>
#pragma pack(2)

struct genexis{

	char emp_name[10];
	int age;
	char emp;
	int salary;
	

};

int main(){

	struct genexis gx;

	printf("%ld", sizeof(gx));

	return 0;

}

