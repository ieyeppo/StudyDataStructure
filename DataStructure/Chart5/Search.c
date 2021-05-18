#include <stdio.h>
#include "Search.h"

int LSearch(int* arr, int size, int searchNum) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == searchNum) return i;
	}
	return -1;
}

void main() {
	int arr[] = { 3,6,8,1,4,2,5,9,7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int index;
	index = LSearch(arr, size, 0);
	if (index == -1)printf("없는 숫자 입니다.\n");
	else printf("arr[%d]\n", index);
}