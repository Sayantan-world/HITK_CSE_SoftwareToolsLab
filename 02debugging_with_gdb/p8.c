#include <stdio.h>

int main()
{
	char buff[15];
	int pass = 0;
	
	printf("\nEnter the password\n");
	gets(buff);

	if(strcmp(buff, "hitcse"))
		printf("\nWrong Password\n");

	else
	{
		printf("\nCorrect Password\n");
		pass = 1;
	}
	
	if(pass)
		printf("\nRoot access granted\n");

	return 0;
}
