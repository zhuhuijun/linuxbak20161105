#include "iostream"
#include "cstdlib"
using namespace std;



/*
����ģ���������

	�D �����������ǰѺ���ģ�崦����ܹ������������͵ĺ���
	�D �������Ӻ���ģ��ͨ���������Ͳ�����ͬ�ĺ���
	�D ��������Ժ���ģ��������α���
	�D�������ĵط���ģ����뱾����б���
	�D�ڵ��õĵط��Բ����滻��Ĵ�����б���
*/

//template���߱����������￪ʼ���з��ͱ��
//typename���߱���������������ΪT �������㿴������T ��Ҫ�ұ���������
//TΪ���ͣ����Ͳ���������
template<typename T>
void swap2(T &a, T &b)
{
	T t = a;
	a = b;
	b = t;
}

int main1()
{
	int x = 1;
	int y = 2;

	//���ͱ�̵ĵ��÷�ʽ��Ϊ����
	//�Զ����� �Ƶ�����
	swap2<int>(x, y);

	//printf("\n%d, %d", x, y);

	float x1 = 1.0;
	float y1 = 2.0;

	//������ ��ʾ����
	swap2<float>(x1, y1);

	//printf("\n%f, %f", x1, y1);
	cout<<"hello...."<<endl;

	system("pause");
	return 0;
}