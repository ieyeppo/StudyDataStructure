#include <stdio.h>
#include <string.h>

typedef struct employee {
	char name[10];
	int year;
	int pay;
}Employee;

void main()
{
	Employee Lee[4] = {
		{"����ȣ", 2014, 4200},
		{"���ѿ�", 2014, 3300},
		{"�̻��", 2014, 3500},
		{"�̻��", 2014, 2900}
	};

	for (int i = 0; i < 4; i++)
	{
		printf("�̸� : %s\n", Lee[i].name);
		printf("�Ի� : %d\n", Lee[i].year);
		printf("���� : %d\n\n", Lee[i].pay);
	}
}