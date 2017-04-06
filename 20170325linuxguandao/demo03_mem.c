#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
//共享内存区的创建
//ipcs -m 查看内存区
int main(int arg,char* argss[])
{	
	int shmid=shmget(IPC_PRIVATE,1024,0666);
	if(shmid < 0){
		printf("error is:%s\n",strerror(errno) );
	}else{
		printf("success \n" );
	}
	return 1;
}