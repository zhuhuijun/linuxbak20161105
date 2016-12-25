#include "iostream"
using namespace std;
template<typename T>
void sortArray(T *a,int num)
{
	int i=0,j=0;
	T tmp;
	for(i=0;i<num;i++)
	{
		for(j=i;j<num;j++)
		{
			if(a[i]<a[j])
			{
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
}
template<class T>
void printArray(T *a,int num)
{
	cout<<endl;
	for(int i=0;i<num;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void main02(int argc,char *argv[])
{
	int a[10]={1,4,56,3,8,43,5,21,45};
	int num=sizeof(a)/sizeof(*a);
	printf("a[]³¤¶È=%d\n",num);
	sortArray<int>(a,num);
	printArray<int>(a,num);
	{
		char buf[]="2qodjkcnl3";
		int len=strlen(buf);
		sortArray<char>(buf,len);
		printArray<char>(buf,len);
	}
	system("pause");
}