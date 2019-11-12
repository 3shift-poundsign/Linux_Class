#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/******************************************
Function: test file output stream
Date: 2019/11/12
Author: ZhangHouJin
******************************************/
int main()
{
	FILE *fp;
	if((fp=fopen("database","r"))==NULL)	
	{
		printf("File cannot be opened\n");
		exit(0);
	}
	else
	{
		char buffer = '\0';
		/*
			// Output by line
			char buffer[100];
			memset(buffer,0,100);
			while(!feof(fp))....
		*/
		while((buffer=fgetc(fp))!=EOF)	// Get file by char
		{
			//fgets(buffer,100,fp);		// Get file by line
			printf("%c",buffer);		// Output by char
		}
		fclose(fp);
	}
	return 0;
}
