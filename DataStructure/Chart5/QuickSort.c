#include <stdio.h>

//퀵정렬
void printArr(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%4d", arr[i]);
	}
	printf("\n");
}

void quickSort(int* arr, int left, int right) {
	if (left >= right) return;
	int pivot = left;
	int lleft = pivot + 1;
	int lright = right;
	int tmp;

	while (lleft <= lright) {
		while (arr[lleft] <= arr[pivot]) lleft++;
		while (arr[lright] >= arr[pivot] && lright > left) lright--;

		if (lleft > lright) {
			tmp = arr[lright];
			arr[lright] = arr[pivot];
			arr[pivot] = tmp;
		}
		else {
			tmp = arr[lright];
			arr[lright] = arr[lleft];
			arr[lleft] = tmp;
		}
	}
	printArr(arr, right);

	quickSort(arr, left, lright - 1);
	quickSort(arr, lright + 1, right);
}

void main() {
	int arr[] = { 3,6,8,1,4,2,5,9,7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("배열 정렬 전 : ");
	printArr(arr, size);

	quickSort(arr, 0, size-1);

	printf("배열 정렬 후 : ");
	printArr(arr, size);
}