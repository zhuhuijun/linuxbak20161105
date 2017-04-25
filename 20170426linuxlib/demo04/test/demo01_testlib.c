#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "upper.h"

int main(int argc,char *argv[])
{
	const char *s="adggafaf33";
	char buf[100];
	memset(buf,0,sizeof(buf));
	upper(s,buf);
	printf("buf>>>>:%s\n",buf );
	return 1;
}