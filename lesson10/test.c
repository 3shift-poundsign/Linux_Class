#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define NUM_OF_STUDENT 3
#define NUM_OF_MARK 6

struct student {
	char name[10];
	int mark[NUM_OF_MARK];
	int sutid;
	int avg;
	int total;
};


/*************************************************
Function: SetMark
Description: Set struct student's data of marks
Input: Structure pointer of student *test
Output: None
Return: None
Author: ZhangH.J.
Date: 2019/10/25
*************************************************/
void setmark(struct student* test)
{
	int mark;
	int con = 0;
	int less_than60 = 0;
	int more_than90 = 0;
	srand(time(NULL));
	while(con < NUM_OF_STUDENT)		// loop for erery struct
	{
		int current;
		for(current=0; current<NUM_OF_MARK;)
		{
			mark = rand()%101;		// mark from 0~100
			if(mark < 60)			// mark < 60
			{
				less_than60 ++;
				if(less_than60 > (int)(6*NUM_OF_STUDENT*0.1));	// num of "less than 60" > 10%
				else
				{
					*(((test+(con))->mark)+(current++)) = mark;
				}
			}
			else if(mark > 90)		// mark > 90
			{
				more_than90 ++;
				if(more_than90 > (int)(6*NUM_OF_STUDENT*0.1));	// num of "more than 90" > 10%
				else
				{
					*(((test+(con))->mark)+(current++)) = mark;
				}
			}
			else
			{
				*(((test+(con))->mark)+(current++)) = mark;
			}
		}
		con ++;		// for next struct
	}
}



void Count_Total_Score(struct student* test)
{
	int total;
	int con = 0;
	while(con < NUM_OF_STUDENT)
	{
		total = 0 ;		// init total variable
		int current;
		for(current=0; current<NUM_OF_MARK; current++)
		{
			total += *(((test+(con))->mark)+(current));
		}
		((test+(con++))->total) = total;		// Record data into Struct
	}
}



/*************************************************
Function: ShowMark
Description: Display struct student's data of marks
Input: Structure pointer of student *test
Output: None
Return: None
Author: ZhangH.J.
Date: 2019/10/25
*************************************************/
void showmark(struct student* test)
{
	int con=0;
	while(con < NUM_OF_STUDENT)	// loop for every struct
	{
		//printf("mark of student %d is %d \n", con, *(test->mark+(con++)));
		printf("The marks of student %d is :", con);
		int current = 0;
		for(current=0;current<NUM_OF_MARK;current++)	// loop for every student 
		{
			printf("%d ",*((test+(con))->mark+(current)));
		}
		printf("\n");
		con ++;
	}
}



void Show_Total_Mark(struct student* test)
{
	int con = 0;
	while(con < NUM_OF_STUDENT)
	{
		printf("The total mark of student %d is : %d\n",con,((test+(con))->total));
		con ++;		// loop for next student
	}
}


int main()
{
	struct student stu[NUM_OF_STUDENT];		// define struct student
	setmark(stu);							// set student's marks
	showmark(stu);							// display student's marks
	Count_Total_Score(stu);					// Calculate total marks of every students
	Show_Total_Mark(stu);					// Display total marks

	return 0;
}




