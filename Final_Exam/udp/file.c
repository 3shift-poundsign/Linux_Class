#include <stdio.h>
#include <string.h>
#define N 16
int main()
{
	FILE *fp;
	int ret;
	char buf[N] = "";
	fp = fopen("./text","r");
	if(fp == NULL)
	{
		perror("fail to open");
		return -1;
	}
	/*
	ret = fread(buf,sizeof(fp),1,fp);
	if(ret < 0||ret == 0)
	{
		perror("fail to read");
		return -1;
	}
	printf("%s",buf);
	memset(buf,0,N);
	*/
	while(fgets(buf,10,fp)!=NULL)
	{
		printf("%s",buf);
	}
	return 0;
}
