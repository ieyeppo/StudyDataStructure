#include <stdio.h>

int main()
{
	int length = 0;
	char input[50];

	printf("���ڿ��� �Է��ϼ���. : ");
	gets(input);
	for (int i = 0; input[i]; i++)
	{
		length++;
	}
	printf("length : %d\n", length);

	return 0;
}