#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NUM 100
int a[NUM];

int main()
{
	int i_60=0;
	int i_90=0;
	int data;
	int total=0;
	srand(time(NULL));
	while(total < 100)
	{
		data = rand()%101;
		if(data < 60)
		{
			i_60++;
			if(i_60>10);
			else a[total++] = data;
		}
		else if(data > 90)
		{
			i_90++;
			if(i_90>10);
			else a[total++] = data;
		}
		else
		{
			a[total++] = data;
		}
	}
	// show data
	for(int i=0; i<100; i++)
	{
		if(i % 10 == 0)
		{
			printf("\n");
		}
		printf("%d ",a[i]);
	}
	printf("\n\n");
	return 0;
}
