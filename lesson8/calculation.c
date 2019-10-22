/*
	Note: Use the following statement to compile, -lm means link math labrary.

	      gcc calculation.c -lm -o calculation

	programe function : calculation number
	Written By        : ZhangH.J.
	Date              : 2019/10/22

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int ERROR_FLAG=0;		// Flag of calculation error

double function(float num1, float num2, char op)
{
	double result;
	switch (op)
	{
		case '+':
			result = num1 + num2;
			break;
		case '-':
			result = num1 - num2;
			break;
		case '*':
			result = num1 * num2;
			break;
		case '/':
			if(num2 == 0)
			{
				printf("Input Error!\n");
				ERROR_FLAG = 1;
				break;
			}
			else
			{
				result = num1 / num2;
				break;
			}
		case '^':
			result = pow((double)num1,(double)num2);
			break;
		default :
			printf("Operation Error!!\n");
			ERROR_FLAG = 1;
			break;
	}
	return result;
}


void show_function()
{
	printf("***********************calculation************************\n");
	printf("**                                                      **\n");
	printf("**                                                      **\n");
	printf("**             function   :    Calculation '+-*/^'      **\n");
	printf("**           Written By   :    ZhangH.J.                **\n");
	printf("**                 Date   :    2019/10/22               **\n");
	printf("**                                                      **\n");
	printf("**                                                      **\n");
	printf("**********************************************************\n");
	printf("\n\n");
}


int main()
{
	float number1,number2;		// Two operation numbers
	char operation;			// The operation char
	double result;			// Calculation result
	char again;			// loop calculation flag
	while (1)
	{
		// Clear screen data
		system("clear");

		// Show calculation funciton
		show_function();

		// Clear input buffer
		setbuf(stdin,NULL);
		fflush(stdin);

		// Input operation char and numbers
		printf("Please input operation char : ");
		scanf("%c",&operation);
		printf("Please input operation number1 : ");
		scanf("%f",&number1);
		printf("Please input operation number2 : ");
		scanf("%f",&number2);

		// Start calculation
		result = function(number1,number2,operation);
		if(ERROR_FLAG == 1)
		{
			printf("Warnning : Operation Error!!\nThe Programe Only Can Calculation '+-*/' !!\n\n");
			ERROR_FLAG = 0;
		}
		else
			printf("\n%.2f %c %.2f = %.2lf\n\n",number1,operation,number2,result);

		// If continue or not
		setbuf(stdin,NULL);
		printf("if you want calculation again? [y]/n");
		scanf("%c",&again);
		if(again == 'y'|| again == '\n')  continue;  // Continue to next loop
		else  break;  // End loop
	}
	return 0;
}












