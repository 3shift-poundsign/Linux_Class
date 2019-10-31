#include <stdio.h>
#include <string.h>

union student {
	int num;
	char name[10];
};

int main()
{
	union student stu;
	stu.num = 1;
	strcpy(stu.name, "ZHJ");
	printf("stu.num : %d\nstu.name : %s\n",stu.num,stu.name);
	return 0;
}
