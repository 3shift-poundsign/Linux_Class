#include <stdio.h>
#include <stdlib.h>

struct student{
	int num;
	char name[10];
	char sex;
}stu[10];

int main()
{
	FILE *fp;
	int i;
	if((fp=fopen("Database","r")) == NULL)
	{
		printf("Error!\n");
		exit(0);
	}
	for(i=0;i<10;i+=2)
	{
		fseek(fp,i*sizeof(struct student),0);
		fread(&stu[i],sizeof(struct student),1,fp);
		printf("%d %s %d\n", stu[i].num, stu[i].name, stu[i].sex);
	}
	fclose(fp);
	return 0;
}
