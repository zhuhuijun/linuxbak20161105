#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main (int arg,char *args[]){
	char s[] = "abc.txt";
	int fd = open(s, O_RDWR | O_APPEND);//用读写追加方式打开文件
	if (fd == -1)
	{
		printf("error is %s\n", strerror(errno));
	}else
	{
		printf("success fd = %d\n", fd);
		char buf[100];
		memset(buf, 0, sizeof(buf));
		strcpy(buf, "hello world\n");
		int i = write(fd, buf, strlen(buf));//这里要用strlen函数
		close(fd);
	}
	return 0;
}
