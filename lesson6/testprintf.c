#include <stdio.h>

int main()
{
	int a = 1234;
	float f = 123.456;
	char ch = 'a';
	char s[] = "HelloWorld!";

	printf("%8d,%2d\n",a,a);
	printf("%f,%8f,%8lf,%.2f\n",f,f,f,f);
	printf("%3c\n",ch);
	printf("%s\n%15s\n%10.5s\n%2.5s\n%.3s\n",s,s,s,s,s);

	printf("%8d,%-8d\n",a,a);
	printf("%10.2f,%-10.1f\n",f,f);
	printf("%10.5s,%-10.3s\n",s,s);

	printf("%08d\n",a);
	printf("%010.2f\n",f);
	printf("%0+8d\n",a);
	printf("%0+10.2f\n",f);

	printf("%o,%#o,%X,%#X\n",a,a,a,a);

	return 0;
}
