#include <stdio.h>
#define NUM 10

int number[NUM] = {23,54,34,65,10,34,45,77,24,22};

int* sort(int *num, int len)
{
	int i,j;
	int temp;
	for(i=0;i<len-1;i++)
	{
		for(j=0;j<len-i-1;j++)
		{
			if(*(num+j) > *(num+j+1))
			{
				temp = *(num+j);
				*(num+j) = *(num+j+1);
				*(num+j+1) = temp;
			}
		}
	}
	return num;
}

void show(int *sorted, int total)
{
	int i;
	for(i=0;i<total;i++)
	{
		if(i%5 == 0) printf("\n");
		printf("%d ",*(sorted+i));
	}
	printf("\n\n");
}


int main()
{
	show(sort(number,NUM),NUM);
	return 0;
}
