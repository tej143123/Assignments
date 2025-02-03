#include <stdio.h>
#include <stdlib.h>


typedef struct {

	int emp_id;
	char emp_name[20];
	int tot_days;
	int month_sal;

} employee;


typedef struct {

	int emp_id;
	int present_days;

} attendance;

int main() {

	employee emp;
	attendance attend;
	FILE *fptr1, *fptr2, *fptr3;


	fptr1 = fopen("emp_ctc.txt", "r");
	if (fptr1 == NULL) {

		perror("Unable to open emp_ctc.txt");
		return 1;

	}


	if (fscanf(fptr1, "emp_id = %d\n", &emp.emp_id) != 1) {

		printf("Error reading emp_id from emp_ctc.txt\n");
		fclose(fptr1);
		return 1;

	}

	if (fscanf(fptr1, "emp_name = %s\n", emp.emp_name) != 1) {

		printf("Error reading emp_name from emp_ctc.txt\n");
		fclose(fptr1);
		return 1;

	}

	if (fscanf(fptr1, "total_days = %d\n", &emp.tot_days) != 1) {

		printf("Error reading total_days from emp_ctc.txt\n");
		fclose(fptr1);
		return 1;

	}

	if (fscanf(fptr1, "month_sal = %d\n", &emp.month_sal) != 1) {

		printf("Error reading month_sal from emp_ctc.txt\n");
		fclose(fptr1);
		return 1;

	}

	fclose(fptr1);


	fptr2 = fopen("emp_attn.txt", "r");
	if (fptr2 == NULL) {

		perror("Unable to open emp_attn.txt");
		return 1;

	}


	if (fscanf(fptr2, "emp_id = %d\n", &attend.emp_id) != 1) {

		printf("Error reading emp_id from emp_attn.txt\n");
		fclose(fptr2);
		return 1;

	}

	if (fscanf(fptr2, "present_days = %d\n", &attend.present_days) != 1) {

		printf("Error reading present_days from emp_attn.txt\n");
		fclose(fptr2);
		return 1;
	}

	fclose(fptr2);


	int absent_days = emp.tot_days - attend.present_days;
	float per_day_salary = (float) emp.month_sal / emp.tot_days;
	float deducted_salary = (per_day_salary * absent_days);
	float total_sal =  (emp.month_sal - deducted_salary);


	fptr3 = fopen("emp_month_sal.txt", "w");
	if (fptr3 == NULL) {

		perror("Failed to create emp_month_sal.txt");
		return 1;

	}


	fprintf(fptr3, "emp_id = %d\n", emp.emp_id);
	fprintf(fptr3, "emp_name = %s\n", emp.emp_name);
	fprintf(fptr3, "total_days = %d\n", emp.tot_days);
	fprintf(fptr3, "month_salary = %d\n", emp.month_sal);
	fprintf(fptr3, "absent_days = %d\n", absent_days);
	fprintf(fptr3, "deducted_salary = %.2f\n", deducted_salary);
	fprintf(fptr3, "Net_salary = %.2f\n", total_sal);

	fclose(fptr3);

	printf("\nFile emp_month_sal.txt has been created successfully.\n");

	return 0;

}
