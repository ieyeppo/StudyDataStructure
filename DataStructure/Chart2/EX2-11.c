#include <stdio.h>
#include <string.h>

void main()
{
	char* ptrArr[2];
	char** ptrptr;

	ptrArr[0] = "Korea";
	ptrArr[1] = "Seoul";

	ptrptr = ptrArr;
	printf("ptrArr[0] �ּ� : %u\n", &ptrArr[0]);
	printf("ptrArr[0] �� : %u\n", ptrArr[0]);
	printf("ptrArr[0] ������ : %c\n", *ptrArr[0]);
	printf("ptrArr[0] �������ڿ� : %s\n\n", *ptrArr);

	printf("ptrArr[1] �ּ� : %u\n", &ptrArr[1]);
	printf("ptrArr[1] �� : %u\n", ptrArr[1]);
	printf("ptrArr[1] ������ : %c\n", *ptrArr[1]);
	printf("ptrArr[1] �������ڿ� : %s\n\n", *(ptrArr+1));

	printf("ptrptr �ּ� : %u\n", &ptrptr);
	printf("ptrptr �� : %u\n", ptrptr);
	printf("ptrptr 1�� ������ : %u\n", *ptrptr);
	printf("ptrptr 2�� ������ : %c\n", **ptrptr);
	printf("ptrptr 2�� �������ڿ� : %s\n\n", *ptrptr);

	printf("\n\n*ptrArr[0] : ");
	for (int i = 0; i < 5; i++) 
		printf("%c ", *(ptrArr[0] + i));
	printf("\n**ptrptr : ");
	for (int i = 0; i < 5; i++)
		printf("%c ", *(*ptrptr + i));

	printf("\n\n*ptrArr[1] : ");
	for (int i = 0; i < 5; i++)
		printf("%c ", *(ptrArr[1] + i));
	printf("\n**ptrptr : ");
	for (int i = 0; i < 5; i++)
		printf("%c ", *(*ptrptr + i));

	getchar();
}