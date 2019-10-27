#include<stdio.h>

int a[5] = {78,12,34,64,59}; 

void show(int *data, int num)
{
    int i;
    for(i=0;i<num;i++)
    {
        printf("%d ",data[i]);
    }
    printf("\n");
}


void function1(int *a,int num1,bool sort)
{
    int temp;
    int i,j;
    for (i=0;i<num1-1;i++)
    {   
        for(j=0;j<num1-1-i;j++)
        {
			if(sort == true)
			{
            	if(*(a+j) < *(a+j+1))
            	{
                	temp = *(a+j);
                	*(a+j) = *(a+j+1);
                	*(a+j+1) = temp;
            	}
			}
			if(sort == false)
            {   
                if(*(a+j) > *(a+j+1))
                {   
                    temp = *(a+j);
                    *(a+j) = *(a+j+1);
                    *(a+j+1) = temp;
                }
			}
        }
    }   
}


void function2()
{
	functinon1(a,5,true);
	show(a,5);
}


void main()
{
	function1(a,5,false);
	show(a,5);
	function2();
	return;
}
