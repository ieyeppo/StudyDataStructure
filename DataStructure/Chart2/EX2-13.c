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
	strcpy(Sptr->name, "이순신");
	Sptr->year = 2015;
	Sptr->pay = 5900;

	printf("이름 : %s\n", Sptr->name);
	printf("입사 : %d\n", Sptr->year);
	printf("연봉 : %d\n", Sptr->pay);

	getchar();
}