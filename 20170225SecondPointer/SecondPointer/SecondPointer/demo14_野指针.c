#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "malloc.h"


char ** spitString_Creat(int mycount)
{
	int i = 0;
	char **myarray = NULL;

	if (mycount > 1000)
	{
		return NULL;
	}

	myarray = (char **)malloc(mycount*sizeof(char *));
	if (myarray == NULL)
	{
		return NULL;
	}
	for (i=0; i<10; i++)
	{
		myarray[i] = (char *)malloc(100);
	}

	return myarray;
}

void  spitString05_free(char **myarray, int ncount)
{
	int i = 0;

	if (myarray == NULL)
	{
		return ;
	}
	for (i=0; i<ncount; i++)
	{
		if(myarray[i]!=NULL)
		{
			free(myarray[i]);
		}
	}
	if (myarray)
	{
		free(myarray);
	}
	myarray = NULL;//垃圾
}
int spitString06_free(char***ppp,int count)  //三级指针分配作输出
{
	int err = 1;
	int i = 0;
	char**src=*ppp;

		if (src == NULL)
		{
			return err;
		}
		for (i = 0;i<count;i++)
		{
			if (src[i] != NULL) free(src[i]);
		}
		free(src);

		*ppp=NULL;;
		return err;
}
void main()
{
	int ncount = 10;
	int i;
	char **myarray = NULL;
	char ** myarray1=NULL;
	char **myarray2=NULL;
	char **myarray3=NULL;//1.定义时指向NULL
	myarray1 = spitString_Creat(10);
	if (myarray1 == NULL)
	{
		printf("func spitString_Creat() \n");
		goto End;
	}
	myarray2 = spitString_Creat(10000);
	if (myarray2 == NULL)
	{
		//2.释放时先判断是否是NULL
		spitString06_free(&myarray1, 10);
		//spitString05_free(myarray1, 10);
		//3.释放完毕再置为NULL
		//myarray1=NULL;
		printf("func spitString_Creat() \n");
		goto End;
	}

	myarray3 = spitString_Creat(10);
	if (myarray3 == NULL)
	{
		printf("func spitString_Creat() \n");
		goto End;
	}

	for (i=0; i<ncount; i++)
	{
		printf("%s\n", myarray[i]);
	}
End:
	if(myarray1!=NULL){
		spitString05_free(myarray1, 10);//释放两次
		myarray1=NULL;
	}

	if(myarray2!=NULL){
		spitString05_free(myarray2, 10);//释放两次
		myarray2=NULL;
	}
	if(myarray3!=NULL){
		spitString05_free(myarray3, 10);//释放两次
		myarray3=NULL;
	}
	system("pause");
}


