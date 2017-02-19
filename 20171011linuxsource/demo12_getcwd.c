#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

void writelog(const char *log)
{
	time_t tDate;
	struct tm *eventTime;
	time(&tDate);//得到系统当前时间
	eventTime = localtime(&tDate);//将time_t数据类型转化为struct tm结构
	int iYear = eventTime->tm_year + 1900;
	int iMon = eventTime->tm_mon + 1;
	int iDay = eventTime->tm_mday;
	int iHour = eventTime->tm_hour;
	int iMin = eventTime->tm_min;
	int iSec = eventTime->tm_sec;

	printf("tm_isdst = %d\n", eventTime->tm_isdst);

	char sDate[16];
	sprintf(sDate, "%04d-%02d-%02d", iYear, iMon, iDay);
	char sTime[16];
	sprintf(sTime, "%02d:%02d:%02d", iHour, iMin, iSec);
	char s[1024];
	sprintf(s, "%s %s %s\n", sDate, sTime, log);
	FILE *p = fopen("my.log", "a+");
	if (p == NULL)
	{
		printf("write log my.log error:%s\n", strerror(errno));
	}else
	{
		fputs(s, p);
		fclose(p);
	}
}
int main(int arg,char *args[])
{
	char buf[1024];
	memset(buf,0,sizeof(buf));
	getcwd(buf,sizeof(buf));
	//当前目录不一定是程序所在的目录
	printf("%s\n",buf );
	writelog(">>begin");
	return 0;
}