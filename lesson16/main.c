#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char str[3][10], temp[10];
	int i,j,k,n=3;
	printf("Please Enter String:");
	for(i=0;i<n;i++)
	{
		gets(str[i]);
	}
	for(i=0;i<n-1;i++)
	{
		k = i;
		for(j=i+1;j<n;j++)
		{
			if(strcmp(str[k],str[j]) > 0)
				k = j;
		}
		if(k!=j)
		{
			strcpy(temp, str[i]);
			strcpy(str[i], str[k]);
			strcpy(str[k], temp);
		}
	}
	if((fp=fopen("Database","w")) == NULL)
	{
		printf("Can't open file!\n");
		exit(0);
	}
	printf("The new sequence:\n");
	for(i=0;i<n;i++)
	{
		fputs(str[i],fp);
		fputs("\n",fp);
		printf("%s\n",str[i]);
	}
	return 0;
}
