#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * retstring();
int main()
{
    char * name2;
    name2 = retstring();
    printf("%s\n",name2);
    return 0;
}

char * retstring()
{
	static char test[10] = "Hello";
	strcpy(test, "Hello1");
    static char name[10];
    strcpy(name,test);
    return name;
}
