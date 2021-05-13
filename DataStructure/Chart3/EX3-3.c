#include <stdio.h>

void main()
{
	int n = 0, * ptr;
	int sale[2][2][4] = {
		{
			{63,84, 140, 130},
			{157,56,48,198}
		},
		{
			{958,34, 170, 194},
			{867,546,915,435}
		}
	};

	ptr = &sale[0][0][0];

	for (int i = 0; i < 16; i++)
	{
		printf("%u slae %2d = %3d\n", ptr, i, *ptr);
		ptr++;
	}
}