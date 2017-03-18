#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc,char *argv[])
{	
	char *args[] ={"/bin/ls","-1",NULL};
	execve("/bin/ls",args,NULL);
	return EXIT_SUCCESS;
}