#include <stdio.h>

void main()
{
	int sale[4] = { 100,200,303,404 };

	for (int i = 0; i < 4; i++)
	{
		printf("address : %u sale[%d] = %d\n", &sale[i], i, sale[i]);
	}
	getchar();
}