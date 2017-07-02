/*
 ============================================================================
 Name        : server.c
 Author      : zhujy
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "pub.h"

int main(int arg,char *args[])
{
	if (arg < 2)
	{
		printf("usage:server port \n");
		return 0;
	}
	int iport = atoi(args[1]);//将第二个参数转化为端口
	if (iport == 0)
	{
		printf("port %d is invilad\n",iport);
		return 0;
	}
	printf ("recv is  begin \n");
	if ( recv_work(iport) == 1)
	{
		printf("recv success\n");
	}else{
		printf("recv failed \n");
	}
	return 1;
}