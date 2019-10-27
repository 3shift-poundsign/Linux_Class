// Just test for file

#include <stdio.h>
#include <stdlib.h>

void Write_Data_to_File(struct student *test)
{
	FILE *fp;
	if((fp=fopen("hello","a+"))==NULL)
	{
		printf("File cannot be opened\n");
		exit(0);
	}
	else
	{
		//printf("File opened for writing\n");
		//fprintf(fp, "This is testing for fprintf...\n");
		//fputs("This is testing for fputs...\n", fp);
		int con = 0;
		int current;
		printf("\nStuID\tName\t\tMarks\t\tTotal\tAverage\tRank\n");
		fprintf(fp,"\nStuID\tName\t\tMarks\t\tTotal\tAverage\tRank\n");
		while(con < NUM_OF_STUDENT)
		{
			printf("%d\t%s\t",(test+(con))->stuid, (test+(con))->name);     // Display StudentID and Name
			fprintf(fp,"%d\t%s\t",(test+(con))->stuid, (test+(con))->name);     // Display StudentID and Name

			for(current=0; current<NUM_OF_MARK; current++)
			{
				printf("%d ",*((test+(con))->mark+(current)));              // Display marks
				fprintf(fp,"%d ",*((test+(con))->mark+(current)));              // Display marks
			}
			printf("\t%d\t%.2lf\t%d\n", (test+(con))->total, (test+(con))->avg, (test+(con))->rank);        // Display Total Average and Ranking.
			fprintf(fp,"\t%d\t%.2lf\t%d\n", (test+(con))->total, (test+(con))->avg, (test+(con))->rank);        // Display Total Average and Ranking.
			con ++;     // for next student
		}
		printf("\n");   // Split display
		fprintf(fp,"\n");   // Split display
	}
	fclose(fp);
	printf("Written to file completion (^o^)!\n");
}




/*************************************************
Function: Show_All_Data
Description: Display All data of every student
Input: Structure pointer of student *test
Output: None
Return: None
Author: ZhangH.J.
Date: 2019/10/26
*************************************************/
void Show_All_Data(struct student *test)
{
    int con = 0;
    int current;
    printf("\nStuID\tName\t\tMarks\t\tTotal\tAverage\tRank\n");
    while(con < NUM_OF_STUDENT)
    {
        printf("%d\t%s\t",(test+(con))->stuid, (test+(con))->name);     // Display StudentID and Name
        for(current=0; current<NUM_OF_MARK; current++)
        {
            printf("%d ",*((test+(con))->mark+(current)));              // Display marks
        }
        printf("\t%d\t%.2lf\t%d\n", (test+(con))->total, (test+(con))->avg, (test+(con))->rank);        // Display Total Average and Ranking.
        con ++;     // for next student
    }
    printf("\n");   // Split display
}
