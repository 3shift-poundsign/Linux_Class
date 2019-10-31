#include <stdio.h>
#include <string.h>

struct student{
	int num;
	char name[10];
	char sex;
};

int main()
{
	struct student stu1;
	printf("sizeof(stu1) : %d \n",sizeof(stu1));
	printf("sizeof(student) : %d \n",sizeof(struct student));
	strcpy(stu1.name,"HelloWorld");
	printf("stu1.name : %s\n",stu1.name);
	return 0;
}
