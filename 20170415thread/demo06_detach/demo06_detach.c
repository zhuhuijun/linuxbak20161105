#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

/**
* 线程的实现
*
*pthread_exit(NULL);终止线程的用法
*线程成为可分离状态不能使用thread_join
*系统会回收资源主线程不等待子进程，主线程并不关心子进程的返回码
*/
void *func(void *arg)
{
	printf("thread start.....\n");
	while(1){
		printf("thread1 living...\n");
		sleep(1);
	}
	printf("thread end.....\n");
	return NULL;
}
int main(int argc,char *args[])
{
	pthread_t thrd;
	if (pthread_create(&thrd,NULL,func,NULL) != 0)
	{
		printf("create error:%s\n",strerror(errno) );;
	}
	pthread_detach(thrd);//设置分离状态
	sleep(1);
	printf("main exit\n");
	return 1;
}