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
*/
void *func(void *arg)
{
	int *p = (int *) arg;
	int i = *p;
	free(p);
	int a=0;
	for(a = 0; a < i;a++){
		printf("thread%d start.....\n",a);
		sleep(1);
	}
	return NULL;
}
int main(int argc,char *args[])
{
	pthread_t thrd,thread2;
	int *i1 = malloc(sizeof(int));
	int *i2 = malloc(sizeof(int));
	*i1=10;
	*i2=2;
	if (pthread_create(&thrd,NULL,func,i1) != 0)
	{
		printf("create error:%s\n",strerror(errno) );;
	}
	if (pthread_create(&thread2,NULL,func,i2) != 0)
	{
		printf("create error:%s\n",strerror(errno) );;
	}
	int *p = NULL;
	pthread_join(thrd,(void **)&p);//主线程挂起等待thrd结束
	printf("p=%d\n",*p );
	pthread_join(thread2,NULL);//主线程挂起等待thrd结束
	printf("main exit\n");
	return 1;
}