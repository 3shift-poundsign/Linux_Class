#include "student.h"
#include <stdio.h>

int main()
{
	char ch;
	printf("welcome to student management system\n");
	while(1)
	{
		printf("(A)DD (D)EL (R)ANK (S)HOW (Q)UIT\n");
		scanf("%c",&ch);
		getchar();
		switch (ch)
		{
			case 'A':
			case 'a':
				add_stu();
				break;
			case 'D':
			case 'd':
				del_stu();
				break;
			case 'r':
			case 'R':
				rank_stu();
				break;
			case 's':
			case 'S':
				show_stu();
				break;
			case 'q':
			case 'Q':
				return 0;
			default:
				printf("err char\n");

		}
	}
}
