#include "iostream"
using namespace std;
class EE{
public:
	int e;
protected:
private:
};
class EE1:virtual public EE{
public:
	int e1;
};
class EE2:virtual public EE{
public:
	int e3;
};
class FF:public EE1,public EE2{
public:
	int e2;
};
//���ؼ̳нӿڲ������������
int main06(int argc,char* argv){
	FF f1;
	f1.e;//e��ָ����ȷ��Ҫ�ڸ��ӿ�ָ��Ϊvirtual
	system("pause");
	return 0;
}