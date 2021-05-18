#include <stdio.h>

//삽입정렬
void printArr(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%4d", arr[i]);
	}
	printf("\n\n");
}

void inserSort(int* arr, int size) {
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[i])
			{
				int tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
				printArr(arr, size);
			}
		}
	}
}

void main() {
	int arr[] = { 3,6,8,1,4,2,5,9,7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("배열 정렬 전 : ");
	printArr(arr, size);

	inserSort(arr, size);

	printf("배열 정렬 후 : ");
	printArr(arr, size);
}