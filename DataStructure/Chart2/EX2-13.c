#include <stdio.h>
#include <string.h>

typedef struct employee
{
	char name[10];
	int year;
	int pay;
}Employee;

void main()
{
	Employee Lee;
	Employee *Sptr = &Lee;
	strcpy(Sptr->name, "�̼���");
	Sptr->year = 2015;
	Sptr->pay = 5900;

	printf("�̸� : %s\n", Sptr->name);
	printf("�Ի� : %d\n", Sptr->year);
	printf("���� : %d\n", Sptr->pay);

	getchar();
}