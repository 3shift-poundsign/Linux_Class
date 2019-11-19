#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
	int number;
	char name[10];
	char sex;
}stu[10];


int main()
{
	int i;
	char temp[3];
	FILE *fp;
	if((fp=fopen("Database","w")) == NULL)		// Open file
	{
		printf("Can't open file!\n");
		exit(0);
	}
	// Write first data into struct
	stu[0].number = 0;
	strcpy(stu[0].name, "ZhangHJ");
	stu[0].sex = 'M';
	// Write data using loop
	for(i=1;i<10;i++)
	{
		stu[i].number = i;
		stu[i].sex = 'M';
		strcpy(stu[i].name, "TestName");
		sprintf(temp,"%d",i);		// format conversion from int to char*
		strcat(stu[i].name, temp);	// Append data into file
	}
	//fscanf(fp, "%d,%s,%c", &stu[0].number, stu[0].name, &stu[0].sex);
	fprintf(fp, "%d,%s,%c\n", stu[0].number, stu[0].name, stu[0].sex);
	for(i=1;i<10;i++)
	{
		fprintf(fp, "%d,%s,%c\n", stu[i].number, stu[i].name, stu[i].sex);
	}
	fclose(fp);
	return 0;
}
