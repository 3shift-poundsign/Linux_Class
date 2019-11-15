#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fsource,*fdest;
	char temp;
	if((fsource = fopen("Database","r")) == NULL)
	{
		printf("Can't read source file!\n");
		exit(0);
	}
	if((fdest = fopen("dest","w")) == NULL)
	{
		printf("Can't write destion file!\n");
		exit(0);
	}
	while((temp=fgetc(fsource))!=EOF)
	{
		fputc(temp,fdest);
		putchar(temp);
	}
	fclose(fsource);
	fclose(fdest);
	putchar(10);
	return 0;
}
