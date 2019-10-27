#include<stdio.h>

int number=123;
extern int c;

void shownum(int num)
{
	c = 999;
	int i=666;
	printf("The number is:%d\n",num);
	printf("I is:%d\n",i);
	printf("C is:%d\n",c);
}
