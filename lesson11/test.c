#include <stdio.h>
#include <string.h>

struct student{
	int num;
	char name[10];
	char sex;
};

struct test{
	int num;
};

int main()
{
	struct student stu1;

	/*
	// Test sizeof struct
	struct test stu2;
	printf("sizeof(stu1) : %d \n",sizeof(stu1));
	printf("sizeof(student) : %d \n",sizeof(struct student));
	strcpy(stu1.name,"HelloWorld");
	printf("stu1.name : %s\n",stu1.name);
	stu1.num = 1;
	stu2.num = stu1.num;
	printf("stu2.num : %d\n",stu2.num);
	*/

	// Show struct data in one line
	stu1.num = 1;
	strcpy(stu1.name, "ZhangHJ");
	stu1.sex = 'm';
	printf("num:%d name:%s sex:%c\n",stu1.num,stu1.name,stu1.sex);

	return 0;
}
