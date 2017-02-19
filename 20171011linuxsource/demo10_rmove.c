#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//int remove(const char *filepath)
//int rname(const char *oldpath,const char *newpath)
int main(int arg,char *args[])
{
	if(arg>1)
		remove(args[1]);
	return 0;
}