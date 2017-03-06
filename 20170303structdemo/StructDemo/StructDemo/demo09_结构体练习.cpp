/*
题目:
//声明结构体类型
struct _AdvTeacher
{
char	*name;
char	*title;
int		age;
char	*addr;
char	*p1;
char	**p2;
};
要求定义一个结构体数组(3个元素)要求从键盘输入并按照名称大小进行排序并打印输出
1.	打印结构体数组需要单独封装成函数
2.	排序结构体数组
2017.03.06
written by zhuhj
*/

#include <iostream>
using namespace std;
#define StructArraySize 3
#define StudentNum 1
typedef struct _AdvTeacher{
	char	*name;
	char	*title;
	int		age;
	char	*addr;
	char	**student;
}_AdvTeacher;
//函数声明
int createStructArray(_AdvTeacher **,int ,int);
int FreeStructArray(_AdvTeacher *,int,int);
int PrintStructArray(_AdvTeacher *,int,int);
int SortStructArray(_AdvTeacher *,int,int);
int main(int arg,char* args[]){
	int rv=0;
	_AdvTeacher *t=NULL;
	rv=createStructArray(&t,StructArraySize,StudentNum);
	if(rv != 0){
		printf("func: createStructArray() _%d error\n",rv);
		goto end;
	}
	for (int i=0;i<StructArraySize;i++)
	{
		printf("请输入第%d位老师的姓名:",i+1);
		scanf("%s",t[i].name);
		printf("请输入第%d位老师的年龄:",i+1);
		scanf("%d",&(t[i].age));
		printf("请输入第%d位老师的职务:",i+1);
		scanf("%s",t[i].title);
		printf("请输入第%d位老师的地址:",i+1);
		scanf("%s",t[i].addr);
		for (int j=0;j<StudentNum;j++)
		{
			printf("请输入第%d位老师的第%d位学生的姓名:",i+1,j+1);
			scanf("%s",t[i].student[j]);
		}
	}
	printf("排序前********************\n");
	rv=PrintStructArray(t,StructArraySize,StudentNum);
	if(rv != 0){
		printf("func:PrintStructArray() _%d error\n",rv);
		goto end;
	}
	rv=SortStructArray(t,StructArraySize,StudentNum);
	if(rv != 0){
		printf("func:SortStructArray() _%d error\n",rv);
		goto end;
	}
	printf("排序后********************\n");
	rv=PrintStructArray(t,StructArraySize,StudentNum);
	if(rv != 0){
		printf("func:PrintStructArray() _%d error\n",rv);
		goto end;
	}

end:
	rv=FreeStructArray(t,StructArraySize,StudentNum);
	if(rv != 0)
	{
		printf("func:FreeStructArray() _%d error\n",rv);
	}
	system("pause");
}
/************************************************************************/
/* 打印函数                                                              */
/************************************************************************/
int PrintStructArray(_AdvTeacher *t,int structArraySize,int studentNum){
	int rv;
	int i;
	int j;
	_AdvTeacher *temp=NULL;
	if(NULL == t){
		rv=1;
		return rv;
	}
	temp=t;
	for (i=0;i<structArraySize;i++)
	{
		printf("第%d位老师的姓名: %s\n",i+1,temp[i].name);
		printf("第%d位老师的年龄: %d\n",i+1,temp[i].age);
		printf("第%d位老师的职务: %s\n",i+1,temp[i].title);
		printf("第%d位老师的地址: %s\n",i+1,temp[i].addr);
		for(j=0;j<studentNum;j++){
			printf("第%d位老师的第%d位学生的姓名：%s \n",i+1,j+1,temp[i].student[j]);
		}
	}
	rv=0;
	return rv;
}
/************************************************************************/
/* 创建数                                                                */
/************************************************************************/
int createStructArray(_AdvTeacher **t,int structArraySize,int studentNum)
{
	int rv=0;
	int i;
	int j;
	if(NULL == t){
		rv=-1;
		return rv;
	}
	_AdvTeacher *temp=NULL;
	temp=(_AdvTeacher *)malloc(structArraySize * sizeof( struct _AdvTeacher));
	if(NULL == temp)
	{
		rv=-2;
		return rv;
	}
	for (i=0;i<structArraySize;i++)
	{
		temp[i].name=(char *)malloc(256 *sizeof(char));
		temp[i].addr=(char *)malloc(256 *sizeof(char));
		temp[i].title=(char *)malloc(256 *sizeof(char));
		if(NULL == temp[i].name || NULL == temp[i].title || NULL == temp[i].addr)
		{
			rv=-3;
			return rv;
		}
		temp[i].student=(char **) malloc(studentNum * sizeof(char *));
		if(NULL == temp[i].student)
		{
			rv=-4;
			return rv;
		}
		for(j=0;j<studentNum;j++){
			temp[i].student[j] = (char *) malloc(256 *sizeof(char));
			if(NULL == temp->student){
				rv= -5;
				return rv;
			}
		}
	}

	*t=temp;
	rv=0;
	return rv;
}
/************************************************************************/
/* 释放内存                                                               */
/************************************************************************/
int FreeStructArray(_AdvTeacher *t,int structArraySize,int studentNum){
	return 1;
}
/************************************************************************/
/* 排序                                                                  */
/************************************************************************/
int SortStructArray(_AdvTeacher *t,int structArraySize,int studentNum)
{
	_AdvTeacher temp;
	int rv=0;
	int i=0;
	int j=0;
	if(NULL == t){
		rv = -1;
		return rv;
	}

	for(i=0;i<structArraySize;i++){
		for (j=i+1;j<structArraySize;j++)
		{
			if(strcmp(t[i].name,t[j].name)>0)
			{
				temp=t[i];
				t[i]=t[j];
				t[j]=temp;
			}
		}
	}
	return rv;
}