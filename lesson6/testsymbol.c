#include<stdio.h>

int main()
{
	float a = 2.34;
	int x = 5;
	int y = 9;
	unsigned m,n;
	int i,j;

	// test (int)
	printf("(int)a=%d,a=%f\n",(int)a,a);
	
	// test ++ and --
	printf("x = 5\ny = 9\n");
	printf("++x = %d\n",++x);
	x=5;y=9;
	printf("x++ = %d\n",x++);
	x=5;y=9;
	printf("--x = %d\n",--x);
	x=5;y=9;
	printf("x-- = %d\n",x--);
	x=5;y=9;
	printf("++x+y++ = %d\n",++x+y++);
	x=5;y=9;
	printf("--x+y++ = %d\n",--x+y++);
	x=5;y=9;
	printf("++x+y-- = %d\n",++x+y--);

	// test unsigned int
	m = 65535;
	i = -1;
	j = m;
	n = i;
	printf("(unsigned)%u-->(int)%d\n",m,j);
	printf("(int)%d-->(ubsigned)%u\n",i,n);

	return 0;
}
