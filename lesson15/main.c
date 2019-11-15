#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char ch,filename[10];
	printf("Please input file name:");
	scanf("%s",filename);
	if((fp=fopen(filename,"w"))==NULL)	
	{
		printf("File cannot be opened\n");
		exit(0);
	}
	ch = getchar();		// get the last Enter character
	printf("Please input a char (end with '#'):");
	//ch = getchar();
	while((ch=getchar()) != '#')
	{
		fputc(ch,fp);
		putchar(ch);
		//ch = getchar();
	}
	fclose(fp);
	putchar(10);		// ASCII '10' is 'LF' which means "line feed/new line"
	return 0;
}
