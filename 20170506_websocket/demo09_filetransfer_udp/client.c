/*
 ============================================================================
 Name        : client.c
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
	if (arg < 4)
	{
		printf("usage:client host port filename\n");
		return 0;
	}
	int iport = atoi(args[2]);//将第二个参数转化为端口
	if (iport == 0)
	{
		printf("port %d is invilad\n",iport);
		return 0;
	}
	printf ("%s send begin \n",args[3]);
	if (send_work(args[1],iport,args[3]) == 1)
	{
		printf("%s send success\n",args[3]);
	}else{
		printf("%s send failed \n",args[3]);
	}
	return 1;
}