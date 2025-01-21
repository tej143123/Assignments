#include <stdio.h>

void insertion_sort(int arr[], int n) {
	for (int i = 0; i <= n - 1; i++) {
		int j = i;
		while (j > 0 && arr[j - 1] > arr[j]) {
			int temp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = temp;
			j--;
		}
	}
}

float findMedian(int *arr1, int n1, int *arr2, int n2) {
	int totalSize = n1 + n2;
	int mergedArray[totalSize];

	for (int i = 0; i < n1; i++) {
		mergedArray[i] = arr1[i];
	}
	for (int i = 0; i < n2; i++) {
		mergedArray[n1 + i] = arr2[i];
	}

	insertion_sort(mergedArray, totalSize);


	if (totalSize % 2 == 0) {

		return (mergedArray[totalSize / 2 - 1] + mergedArray[totalSize / 2]) / 2.0;
	} else {

		return mergedArray[totalSize / 2];
	}
}

int main() {
	int n1, n2;

	printf("Enter the size of the first array: ");
	scanf("%d", &n1);
	int arr1[n1];


	printf("Enter the elements of the first array:\n");
	for (int i = 0; i < n1; i++) {
		scanf("%d", &arr1[i]);
	}


	printf("Enter the size of the second array: ");
	scanf("%d", &n2);
	int arr2[n2];


	printf("Enter the elements of the second array:\n");
	for (int i = 0; i < n2; i++) {
		scanf("%d", &arr2[i]);
	}

	float median = findMedian(arr1, n1, arr2, n2);
	printf("The median of the two arrays is: %.2f\n", median);

	return 0;
}

