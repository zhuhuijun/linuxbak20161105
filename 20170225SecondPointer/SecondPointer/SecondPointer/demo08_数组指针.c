#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//����ָ��
int main0800000(int arg,char *args[]){
	int a;
	int *p=NULL;
	typedef int(MyArr5)[5];
	//����һ�� ָ��  ��������  ��  ָ�����
	MyArr5 *pArray;
	{
		int j=0;
		int *pi=&j;
	}
	{
		int i=0;
		//buf[10][30]
		//a1����������Ԫ�صĵ�ַ������������ĵ�ַ
		//a1ָ�����->ָ�볣��(����ָ��)
		//����:�������ı�ָ���ָ��  Ϊ��ô��const?�ڶ���[5]ʱ������Ϊ�����õ�ԭʼ���ڴ��ַ�������Ͱ�a1����const
		//
		int a1[5]={1,2,3,45,5};
		//������ָ�븳ֵ
		MyArr5 *pArray=&a1;//4���ֽ�
		//ʹ������ָ��ȥ��������
		for (i=0;i<5;i++)
		{
			//a1[i]=i;
			(*pArray)[i]=i;
			printf("%d\n",(*pArray)[i]);
		}
		{
			//����ָ���������͵�ָ�����
			//	typedef int(MyArr5_1)[5];
			//����һ��   ����ָ�� ����
			typedef int(*PMyArr5)[5];
			//�����������������
			PMyArr5 myp=NULL;//4���ֽ�
			int b[5]={6,7,8,9,0};
			myp=&b;
			for (i=0;i<5;i++)
			{
				//a1[i]=i;
				//(*pArray)[i]=i;
				printf("%d  ",(*myp)[i]);
			}
		}
		{
			int c[5]={6,7,8,9,0};
			//����ָ��
			//����һ��ָ�������ָ�����
			int (*myarra)[5]=&c;
			for (i=0;i<5;i++)
			{
				//a1[i]=i;
				//(*pArray)[i]=i;
				printf("%d  ",(*myarra)[i]);
			}
		}
	}
	system("pause");
}