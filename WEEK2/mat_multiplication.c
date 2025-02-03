#include<stdio.h>
#include<stdlib.h>

void memory_allocation(int ***arr1, int ***arr2, int n1, int m1, int n2, int m2) {
	*arr1 = (int**)malloc(sizeof(int*) * n1);
	for (int i = 0; i < n1; i++) {
		(*arr1)[i] = (int*)malloc(sizeof(int) * m1);
	}

	*arr2 = (int**)malloc(sizeof(int*) * n2);
	for (int i = 0; i < n2; i++) {
		(*arr2)[i] = (int*)malloc(sizeof(int) * m2);
	}
}

void user_input(int **arr1, int **arr2, int n1, int m1, int n2, int m2) {
	printf("\nEnter the elements of the first matrix:\n");
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m1; j++) {
			printf("\nEnter the value of arr1[%d][%d] : ", i, j);
			scanf("%d", &arr1[i][j]);
		}
	}

	printf("\nEnter the elements of the second matrix:\n");
	for (int i = 0; i < n2; i++) {
		for (int j = 0; j < m2; j++) {
			printf("\nEnter the value of arr2[%d][%d] : ", i, j);
			scanf("%d", &arr2[i][j]);
		}
	}
}

int** matrix_multiplication(int **arr1, int **arr2, int n1, int m1, int n2, int m2, int *rows, int *cols) {
	int **result_matrix = (int**)malloc(sizeof(int*) * n1);
	for (int i = 0; i < n1; i++) {
		result_matrix[i] = (int*)malloc(sizeof(int) * m2);
		for (int j = 0; j < m2; j++) {
			result_matrix[i][j] = 0;
		}
	}

	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m2; j++) {
			for (int k = 0; k < m1; k++) {
				result_matrix[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}

	*rows = n1;
	*cols = m2;
	return result_matrix;
}

void print_resultant_matrix(int **result, int rows, int cols) {
	printf("\nThe resultant matrix is:\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("\nThe value of resultant_matrix[%d][%d] : ", i, j);
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int n1, m1, n2, m2, rows, cols;
	int **arr1, **arr2;

	printf("\nEnter the number of rows in the first matrix: ");
	scanf("%d", &n1);
	printf("\nEnter the number of columns in the first matrix: ");
	scanf("%d", &m1);

	printf("\nEnter the number of rows in the second matrix: ");
	scanf("%d", &n2);
	printf("\nEnter the number of columns in the second matrix: ");
	scanf("%d", &m2);

	if (m1 != n2) {
		printf("\nMatrix multiplication is not possible with these dimensions.\n");
		return 1;
	}

	if(n1 == 0|| m1 == 0 || n2 == 0 || m2 == 0){
		printf("\nMatrix multiplication is not possible with these dimensions.\n");
		return 0;
	}

	memory_allocation(&arr1, &arr2, n1, m1, n2, m2);
	user_input(arr1, arr2, n1, m1, n2, m2);

	int **result = matrix_multiplication(arr1, arr2, n1, m1, n2, m2, &rows, &cols);
	print_resultant_matrix(result, rows, cols);
       
       	
	for (int i = 0; i < n1; i++) free(arr1[i]);
	free(arr1);

	for (int i = 0; i < n2; i++) free(arr2[i]);
	free(arr2);

	for (int i = 0; i < rows; i++) free(result[i]);
	free(result);

	return 0;
}

