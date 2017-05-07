#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

/**
* 线程的实现
*
*/
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void *func(void *arg)
{
	pthread_mutex_lock(&mutex);
	int *a = (int *)arg;
	int i = 0 ;
	printf("thread%d start.....\n",*a);
	for (;i<10;i++){
		printf("thread%d-%d\n",*a,i );
		sleep(1);
	}
	printf("thread%d end.....\n",*a);
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}


int main(int argc,char *args[])
{
	pthread_t thrd1,thrd2;
	int i[2];
	i[0]=1;
	i[1]=2;
	if (pthread_create(&thrd1,NULL,func,&i[0]) != 0)
	{
		printf("create error:%s\n",strerror(errno) );
	}
	if (pthread_create(&thrd2,NULL,func,&i[1]) != 0)
	{
		printf("create error:%s\n",strerror(errno) );
	}
	pthread_join(thrd1,NULL);
	pthread_join(thrd2,NULL);
	sleep(1);

	printf("main exit\n");
	return 1;
}