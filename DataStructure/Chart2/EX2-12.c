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
		{"이진호", 2014, 4200},
		{"이한영", 2014, 3300},
		{"이상원", 2014, 3500},
		{"이상범", 2014, 2900}
	};

	for (int i = 0; i < 4; i++)
	{
		printf("이름 : %s\n", Lee[i].name);
		printf("입사 : %d\n", Lee[i].year);
		printf("연봉 : %d\n\n", Lee[i].pay);
	}
}