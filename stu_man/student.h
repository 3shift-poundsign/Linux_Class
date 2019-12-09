#ifndef __STUDETN_H__
#define __STUDENT_H__

typedef struct 
{
	int num;
	char name[64];
	float score;
}STU;


void add_stu();
void del_stu();
void rank_stu();
void show_stu();

#endif
