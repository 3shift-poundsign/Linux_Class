// Test for file

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	if((fp=fopen("hello","a+"))==NULL)
	{
		printf("File cannot be opened\n");
		exit(0);
	}
	else
	{
		printf("File opened for writing\n");
		fprintf(fp, "This is testing for fprintf...\n");
		fputs("This is testing for fputs...\n", fp);
	}
	fclose(fp); 

	return 0;
}
