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
*/
void *func(void *arg)
{
	printf("thread start.....\n");
	while(1){
		printf("thread1 living...\n");
		sleep(1);
	}
	printf("thread end.....\n");


	int *p =malloc(sizeof(int));
	*p = 1;
	return p;
}

void *func2(void *arg)
{
	sleep(5);
	pthread_t thr;
	thr = *(pthread_t *)arg;
	pthread_cancel(thr);
	printf("cancel other pthread\n");

	int *p =malloc(sizeof(int));
	*p = 2;
	return p;
}

int main(int argc,char *args[])
{
	pthread_t thrd1,thrd2;
	if (pthread_create(&thrd1,NULL,func,NULL) != 0)
	{
		printf("create error:%s\n",strerror(errno) );
	}
	if (pthread_create(&thrd2,NULL,func2,&thrd1) != 0)
	{
		printf("create error:%s\n",strerror(errno) );
	}
	int *p1 = NULL;
	int *p2 = NULL;
	pthread_join(thrd1,(void **)&p1);
	pthread_join(thrd2,(void **)&p2);
	printf("p1 =%d\n", *p1);
	printf("p2 =%d\n", *p2);
	sleep(1);

	printf("main exit\n");
	return 1;
}