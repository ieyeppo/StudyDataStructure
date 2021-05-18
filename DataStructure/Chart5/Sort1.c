#include <stdio.h>

void insrtionsort(int* arr, int size) {
	for (int i = 1; i < size; i++) {
		if (arr[i] < arr[i - 1]) {
			int temp = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = temp;
		}
	}
}

void main() {

}