#include <stdio.h>

void main()
{
	char str[20] = "Data Structure!";
	int cnt = 0;

	printf("\n���� �迭 str[] : ");

	for (int i = 0; str[i]; i++) 
	{
		printf("%c", str[i]);
		cnt++;
	}
	getchar();
	printf("%d", cnt);
}