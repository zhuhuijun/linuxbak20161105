#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int arg, char* argv[])
{
	printf("a beginning....\n");
	int fd = open ("a.txt",O_RDONLY);
	if (fd == -1 )
	{
		printf(" error is :%s\n",strerror(errno) );
		return -1;
	}
	pid_t pid = fork();
	if (pid < 0){
		printf("fork error :%s\n",strerror(errno) );
		return -1;
	}
	if (pid > 0) {
		close(fd);//文件描述符的引用-1
	}
	if (pid == 0){
		char s[128];
		memset(s,0,sizeof(s));
		sprintf(s,"%d",fd);//把描述符转为字符串
		char *args[] = {"b",s,NULL};
		if (execve("b",args,NULL) == -1 ){
			printf("execve failed %s\n", strerror(errno));
		}
	}
	printf("a end\n");
	return 1;
}
