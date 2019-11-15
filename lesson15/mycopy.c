#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	FILE *fsource,*fdest;
	char *filename;
	char temp;
	printf("Source:%s\nDestion:%s\n",argv[1],argv[2]);
	//strcpy(filename,argv[0]);
	if((fsource = fopen(argv[1],"r")) == NULL)
	{
		printf("Can't read source file!\n");
		exit(0);
	}
	if((fdest = fopen(argv[2],"w")) == NULL)
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
	//putchar(10);
	return 0;
}
