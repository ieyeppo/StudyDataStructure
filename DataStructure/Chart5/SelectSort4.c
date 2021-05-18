#include <stdio.h>

//선택정렬
void printArr(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%4d", arr[i]);
	}
	printf("\n");
}

void selectSort(int* arr, int size) {
	for (int i = 0; i < size -1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] > arr[j]) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
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

	selectSort(arr, size);

	printf("배열 정렬 후 : ");
	printArr(arr, size);
}