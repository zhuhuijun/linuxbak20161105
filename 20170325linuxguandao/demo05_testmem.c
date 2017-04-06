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
//使用共享内存区进行读写的测试
int main(int arg,char* args[])
{	
	char *shumbuf;
	int shmid = 0;
	if (arg > 2 ){
		shmid = atoi(args[1]);
		shumbuf = shmat(shmid,0,0);
		if(atoi(args[2]) == 1){
			scanf("%s\n",shumbuf);
		}
		if(atoi(args[2]) == 2){
			printf("%s\n",shumbuf);
		}
		shmdt(shumbuf);//附加的内存地址
	}	
	return 1;
}