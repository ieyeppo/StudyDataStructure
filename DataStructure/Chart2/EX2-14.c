#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long int fact(int);

void main()
{
	int n, result;
	printf("점수 입력 : ");
	scanf("%d", &n);
	result = fact(n);
	printf("\n%d의 팩토리얼 = %d\n", n, result);
	getchar(); getchar();
}

long int fact(int n)
{
	int value;
	if (n <= 1) {
		printf("\nfact(1) 함수 호출!\n");
		printf("\nfact(1) 값 1 반환!\n");
		return 1;
	}
	else {
		printf("\nfact(%d) 함수 호출!\n", n);
		value = (n * fact(n - 1));
		printf("\nfact(%d) 값 %ld 반환!\n", n, value);
		return value;
	}
}