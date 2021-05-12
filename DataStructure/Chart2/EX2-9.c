#include <stdio.h>

void main() 
{
	char str1[20] = "Dreams com true!", str2[20], * ptr1, * ptr2;

	ptr1 = str1;
	printf("str1 Address : %u \t ptr1 = %u\n", str1, ptr1);
	printf("str1 = %s\nptr1 = %u\n\n", str1, ptr1);
	printf("%s", ptr1 + 7);
	ptr2 = &str1[7];
	printf("\n %s \n\n", ptr2);

	for (int i = 16; i >= 0; i--) 
	{
		putchar(*(ptr1 + i));
	}
	for (int i = 0; i < 20; i++)
	{
		str2[i] = *(ptr1 + i);
	}
	printf("\n\nstr1 = %s\n", str1);
	printf("str2 = %s\n", str2);

	*ptr1 = 'p';
	*(ptr1 + 1) = 'e';
	*(ptr1 + 2) = 'a';
	*(ptr1 + 3) = 'c';
	*(ptr1 + 4) = 'e';
	printf("\n\nstr1 = %s\n", str1);

	getchar();
}