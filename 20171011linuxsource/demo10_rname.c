#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//int remove(const char *filepath)
//int rename(const char *oldpath,const char *newpath)
int main(int arg,char *args[])
{
	if(arg>2)
		rename(args[1],args[2]);
	return 0;
}