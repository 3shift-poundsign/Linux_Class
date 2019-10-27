#include<stdio.h>

void sort(int *a,int number)
{
	int temp;
	int i,j;
	for (i=0;i<number-1;i++)
	{
		for(j=0;j<number-1-i;j++)
		{
			if(*(a+j) < *(a+j+1))
			{
				temp = *(a+j);
				*(a+j) = *(a+j+1);
				*(a+j+1) = temp;
			}
		}
	}
}

void show(int *data, int num)
{
	int i;
	for(i=0;i<num;i++)
	{
		printf("%d ",data[i]);
	}
	printf("\n");
}


void main()
{
	int i;
	int a[5] = {12,34,76,66,98};
	int *p;
	p = a;
	show(a,5);
	sort(p,5);
	show(a,5);
	return;
}
