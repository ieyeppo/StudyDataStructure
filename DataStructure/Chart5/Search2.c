#include <stdio.h>

int BSearch(int* arr, int size, int target) {
	for (int i = 0; i < size / 2; i++) {
		if (arr[i] == target) return i;
		else if (arr[size - i] == target) return size - i;
	}
	return -1;
}

void main() {
	int arr[] = { 3,6,8,1,4,2,5,9,7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int index;

	index = BSearch(arr, size, 8);
	if (index == -1) printf("Å½»ö½ÇÆÐ.\n");
	else printf("arr[%d]\n", index);
}