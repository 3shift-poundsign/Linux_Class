#include <stdio.h>
#include <stdlib.h>

struct student{
	char name[10];
	int num;
	int age;
	char addr[15];
}stu[10];

int main()
{
	FILE *fp;
	int i;
	if((fp=fopen("Database","rb")) == NULL)
	{
		printf("Error!\n");
		exit(0);
	}
	for(i=0;i<10;i+=2)
	{
		fseek(fp,i*sizeof(struct student),0);
		fread(&stu[i],sizeof(struct student),1,fp);
		printf("%-10s %4d %4d %-15s\n",stu[i].name, stu[i].num, stu[i].age, stu[i].addr);
	}
	fclose(fp);
	return 0;
}
