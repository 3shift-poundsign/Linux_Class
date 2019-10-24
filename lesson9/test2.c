// 函数指针测试
#include <stdio.h>

int plus(int a, int b)
{
	return (a+b);
}

int minus(int a,int b)
{
	return (a-b);
}

int test(int a,int b,int (*pFunc)(int,int))
{
	return ((*pFunc)(a,b));
}


int main()
{
	int x = 5;
	int y = 8;
	int (*pFunc)(int, int);

	pFunc = plus;
	printf("plus(x,y) = %d\n",(*pFunc)(x,y));

	pFunc = minus;
	printf("minus(x,y) = %d\n",(*pFunc)(x,y));

	printf("test(15,5,plus) = %d\n",test(15,5,plus));
	printf("test(15,5,minus) = %d\n",test(15,5,minus));

	return 0;
}
