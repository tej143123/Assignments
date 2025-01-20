#include<stdio.h>

struct genexis1{

	char emp_name[100];
	char emp_id[20];
	char org_location[50];
	int emp_size;
};

union  genexis2{

	char emp_name[100];
	char emp_id[20];
	char org_location[50];
	int emp_size;
};


int main(){

	int a;
	float b;
	char c;
	double d;
	int *e;
	struct genexis1 gx1;
	union genexis2 gx2;

	printf("The size of int data type is : %lu\n ", sizeof(a));

	printf("The size of float data type is : %lu\n ", sizeof(b));

	printf("The size of char data type is : %lu\n ", sizeof(c));

	printf("The size of double data type is : %lu\n ", sizeof(d));

	printf("The size of pointer is : %lu\n", sizeof(e));

	printf("The size of struct is : %lu\n ", sizeof(gx1));

	printf("The size of union is : %lu\n ", sizeof(gx2));

	return 0;

}     

