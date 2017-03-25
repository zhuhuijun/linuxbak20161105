#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "testlib.h"
int main(int argc, char const *argv[])
{
	printf("max=%d\n",max(4,5) );
	return EXIT_SUCCESS;
}