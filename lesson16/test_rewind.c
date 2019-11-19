#include <stdio.h>

int main()
{
	FILE *fp1,*fp2;
	fp1 = fopen("data1","r");
	fp2 = fopen("data2","w");
	while(!feof(fp1))
	{
		putchar(fgetc(fp1));
	}
	putchar(10);
	rewind(fp1);
	while(!feof(fp1))
	{
		fputc(fgetc(fp1),fp2);
	}
	fclose(fp1);
	fclose(fp2);

	return 0;
}
