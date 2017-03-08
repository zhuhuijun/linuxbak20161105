/*
	1.使用结构体的方式读取和写入文件
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct Student{
	char name[10];
	int num;
	int age;
	char addr[15];
} Student;
#define  SIZE 5
int mainwrite()
{
	int i;
	FILE *fp=NULL;
	Student student[5];
	if((fp=fopen("d:/student.data","wb")) == NULL){
		printf("can not open file\n");
		return;
	}
	for (i=0;i<5;i++)
	{
		memset(&student[i],0,sizeof(struct Student));
		sprintf(student[i].name,"name%d",i+1);
		student[i].num=i*10;
	}
	for (i=0;i<5;i++)
	{
		if(fwrite(&student[i].name,sizeof(Student),1,fp) != 1){
			printf("file write error\n");
		}
	}
	fclose(fp);
	return 1;
}
void display(){
	FILE *fp;
	int i;
	Student student[SIZE];
	char *filename="d:/student.data";
	for (i=0;i<SIZE;i++)
	{
		memset(&student[i],0,sizeof(struct Student));
	}
	if((fp=fopen(filename,"rb")) == NULL){
		printf("can not open file\n");
		return;
	}
	for (i=0;i<SIZE;i++)
	{
		fread(&student[i].name,sizeof(Student),1,fp);
		printf("%s,%d\n ",student[i].name,student[i].num);
	}
	fclose(fp);
}
int main(int arg,char* args[])
{
	mainwrite();
	display();
	system("pause");
	return 1;
}