#include <stdio.h>


int main(void)
{
	int arr[8][9];

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			arr[i][j] = (i + 2) * (j + 1);
		}
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%2d x %2d = %2d\n", i + 2, j + 1, arr[i][j]);
		}
		printf("\n\n");
	}


	return 0;
}