#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
int trimSpace_ok2(char *mybuf, char *outbuf)
{
	int count = 0;
	int i = 0, j = 0;

	char *p = mybuf;
	j = strlen(p) - 1;

	while (isspace(p[i]) && p[i] != '\0')
	{
		i++;
	}

	while (isspace(p[j]) && j > 0)
	{
		j--;
	}
	count = j - i + 1;

	memcpy(outbuf, mybuf + i, count);
	outbuf[count] = '\0';
	return 0;
}


int getKeyByValue(char *keyvaluebuf, char *keybuf, char *valuebuf, int * valuebuflen)
{
	int rv = 0;
	char tmp[2048 * 10] = {0};
	char *p = NULL;
	p = strstr(keyvaluebuf, keybuf);
	if (p == NULL)
	{
		return 0;
	}
	p = p + strlen(keybuf);
	p = strstr(keyvaluebuf, "=");
	if (p == NULL)
	{
		return 0;
	}
	p = p + 1;
	rv = trimSpace_ok2(p, tmp);
	if (rv != 0)
	{
		printf("func trimSpace_ok2() err:%d\n", rv);
		return rv;
	}
	strcpy(valuebuf, tmp);
	*valuebuflen = strlen(tmp);
	return 0;
}
int my_atoi(char* pstr)
{
	int Ret_Integer = 0;
	int Integer_sign = 1;
	if (pstr == NULL)
	{
		printf("err is %s\n",strerror(errno));
		printf("Pointer is NULL\n");
		return 0;
	}
	if (*pstr == '-')
	{
		Integer_sign = -1;
	}
	if (*pstr == '-' || *pstr == '+')
	{
		pstr++;
	}

	while (*pstr >= '0' && *pstr <= '9')
	{
		Ret_Integer = Ret_Integer * 10 + *pstr - '0';
		pstr++;
	}
	Ret_Integer = Integer_sign * Ret_Integer;
	return Ret_Integer;
}
int dak(int a[],int *count)
{
	int i = 0;
	char buf[100]={0};
	char *keybuf = "index";
	char valuebuf[1024]={0};
	int valuebuflen = 0;
	int rv = 0;
	FILE *fd = fopen("c.txt","r+");
	if(fd == NULL)
	{
		rv = -1;
		printf("err is %s\n",strerror(errno));
		printf("error dak pf %d",rv);
		return rv;
	}
	while(fgets(buf,sizeof(buf),fd) != NULL)
	{
		rv = getKeyByValue(buf,keybuf,valuebuf,&valuebuflen);
		if(rv != 0){
			rv = -2;
			return rv;
		}
		a[i] = my_atoi(valuebuf);
		i++;
	}
	fclose(fd);
	*count = i;
	return rv;
}
void bubble_sort(int *a, int n)//n为数组a的元素个数
{
	int i = 0, j, temp = 0;
	for (; i < n; i++)
	{

		for (j = i + 1; j<n; j++)
		{
			if (a[i]>a[j])//数组元素大小按升序排列
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
void pjs(int a[], int count)
{
	int  i = 0;
	float pjz = 0, sum = 0;
	for (; i < count;i++)
	{
		sum += a[i];
	}
	pjz = sum / count;
	printf("pingjunzhi= %f", pjz);
}
int main(int argc,char* argv[])
{
	int buf[128]={0};
	int i = 0;
	int *count =&i;
	dak(buf,count);
	bubble_sort(buf, i);
	printf("max_%d\n", buf[i-1]);
	printf("min_%d\n", buf[0]);
	pjs(buf,i);
	return EXIT_SUCCESS;
}