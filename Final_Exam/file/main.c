#include <stdio.h>
#include <string.h>
#define N 64

int main()
{
	FILE *fp;
	char buf[N];
	int ch;
	memset(buf,0,N);
	if((fp = fopen("DataBase","a+")) == NULL)
	{
		printf("Fail to open\n");
		return -1;
	}
	/*
	while(fgets(buf,10,fp))
	{
		printf("%s",buf);
	}
	*/
	while((ch = fgetc(fp)) != EOF)
	{
		printf("%c",ch);
	}
	printf("\nFile End\n");
	return 0;
}
