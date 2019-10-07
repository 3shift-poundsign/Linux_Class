#include<stdio.h>

int add(int m)
{
	int i,n=0;
	for(i=1;i<=m;i++)
		n+=i;
	printf("The sum of 1-%d in add is %d\n",m,n);
}

int main()
{
	int i,n=0;
	add(50);
	for(i=1;i<=50;i++)
	{
		n+=i;
	}
	printf("The sum of 1-50 is %d\n",n);
	return 0;
}
