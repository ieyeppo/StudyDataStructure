#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long int fact(int);

void main()
{
	int n, result;
	printf("���� �Է� : ");
	scanf("%d", &n);
	result = fact(n);
	printf("\n%d�� ���丮�� = %d\n", n, result);
	getchar(); getchar();
}

long int fact(int n)
{
	int value;
	if (n <= 1) {
		printf("\nfact(1) �Լ� ȣ��!\n");
		printf("\nfact(1) �� 1 ��ȯ!\n");
		return 1;
	}
	else {
		printf("\nfact(%d) �Լ� ȣ��!\n", n);
		value = (n * fact(n - 1));
		printf("\nfact(%d) �� %ld ��ȯ!\n", n, value);
		return value;
	}
}