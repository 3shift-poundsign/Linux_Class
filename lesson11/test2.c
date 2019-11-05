#include <stdio.h>

union student {
	int data1;
	int data2;
};

int main()
{
	union student stu;
	stu.data1 = 1;
	stu.data2 = 2;
	printf("stu.data1 : %d\nstu.data2 : %d\n",stu.data1,stu.data2);
	return 0;
}
