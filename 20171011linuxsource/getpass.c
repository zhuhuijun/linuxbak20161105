#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main (int arg,char *args[]){
	char *s=getpass("please input:");
	printf("%s\n",s );
	return 0;
}
