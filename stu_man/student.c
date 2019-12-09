#include "student.h"
#include <stdio.h>
#define N 50

STU student[N];
int pos = -1;

static int isFull()
{
	return pos == N - 1;
}
void add_stu()
{
	if(isFull())
	{
		printf("system is full\n");
		return;
	}
	int tmp;
	STU s;
	printf("please input pos:\n");
	scanf("%d",&tmp);
	getchar();
	if(tmp < 0||tmp > pos + 1)
	{
		printf("err pos\n");
		return;
	}
	printf("please input num:\n");
	scanf("%d",&s.num);
	getchar();
	printf("please input name:\n");
	scanf("%s",s.name);
	printf("please input score:\n");
	scanf("%f",&s.score);
	getchar();

	int pos_tmp = pos;
	while(pos_tmp >= tmp)
	{
		student[pos_tmp + 1] = student[pos_tmp];
		pos_tmp--;
	}
	student[tmp] = s;
	pos++;

	return;
}
void del_stu()
{
	int temp;
	printf("Please input pos:");
	scanf("%d",&temp);
	getchar();
	if(temp<0 || temp>pos-1)
	{
		printf("Error pos");
		return;
	}
	int pos_temp = temp;
	while(pos_temp <= pos)
	{
		student[pos_temp] = student[pos_temp + 1];
		pos_temp ++;
	}
	pos --;
	return;

}
void rank_stu()
{

	return;

}
void show_stu()
{
	int i;
	for(i = 0;i <= pos;i++)
	{
		printf("num:%d  name:%s  score:%f\n",student[i].num,student[i].name,student[i].score);
	}
	return;

}
