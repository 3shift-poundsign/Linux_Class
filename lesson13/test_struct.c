#include<stdio.h>

struct iofeld {
	unsigned int com : 4;
	unsigned int spi : 3;
	int : 0;
	unsigned int can : 2;
	int : 0;
}serial;

int main()
{
	serial.com = 7;
	//serial.spi = 10;	// OverFlow here !
	serial.spi = 2;
	serial.can = 3;
	printf("serial.com:%d\nserial.spi:%d\nserial.can:%d\n",serial.com,serial.spi,serial.can);
	return 0;
}
