#include<stdio.h>

struct A {
	int a;
	char b;
	float c;
	char name[10];
}test;

struct B {
	int a;
	int b;
	int c;
}arr[2] = {10,3,21,7,29,1};

struct C {
	int num;
	char name[10];
}a[3] = {{1,"Beijing"},{2,"Zhanghou"},{3,"Houjin"}};

struct D {
	char a;
	double b;
	int c;
};

union E {
	int a;
	char b;
	float c;
};

enum F {
	apple,
	pear,
	orange
};

int main()
{
 	printf("%d\n",sizeof(test));
 	printf("%d\n",arr[0].b * arr[1].c);
	struct C *p;
	p = a+1;
	printf("%d,%c\n",p->num,(*p).name[1]);
	printf("%d\n",sizeof(struct D));
	printf("%d\n",sizeof(union E));	
	printf("%d\n",sizeof(enum F));
	return 0;
}
