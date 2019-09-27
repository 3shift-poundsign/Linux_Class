#include<stdio.h>
#include<stdlib.h>

struct node {
	int num;
	struct node* next;
} stu,*pstu;

int main(){
	char *p;

	// Test struct size
	printf("sizeof int :%d\n",sizeof(stu.num));
	printf("sizeof next :%d\n",sizeof(stu.next));
	printf("sizeof struct :%d\n",sizeof(stu));
	printf("sizeof *stu.next: %d\n",sizeof(*stu.next));
	printf("sizeof pstu: %d\n",sizeof(pstu));
	printf("sizeof *pstu: %d\n",sizeof(*pstu));

	// Test char* size
	printf("sizeof p: %d\n",sizeof(p));
	printf("sizeof *p: %d\n",sizeof(*p));

	// Test malloc stu size
	printf("sizeof malloc stu: %d\n",sizeof(malloc(sizeof(stu))));
	
	// malloc test
	struct node *student = malloc(sizeof(char));
	student = &stu;
	stu.num = 123;
	printf("stu.num is: %d\n",stu.num);

	return 0;
}
