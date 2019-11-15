#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char ch;
	if((fp=fopen("Database","a+")) == NULL)
	{
		printf("Can't open this file...\n");
		exit(0);
	}
	printf("Please input string (end with '$'):");
	while((ch=getchar()) != '$')
	{
		fputc(ch,fp);
		putchar(ch);
	}
	fclose(fp);
	putchar(10);
	return 0;
}
