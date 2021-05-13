#include <stdio.h>

void main()
{
	int n = 0, * ptr;

	int sale[2][4] = {
		{63, 84, 140, 34},
		{234,235,54,85}
	};

	ptr = &sale[0][0];

	for (int i = 0; i < 8; i++)
	{
		printf("address : %u sale %d = %d\n", ptr, i, *ptr);
		ptr++;
	}

	//---------------------------------------------------------------

	int (*ptr2)[4] = sale;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("ptr2 : %u\n", ((*ptr2 + i))[j]);
		}
	}


	getchar();
}