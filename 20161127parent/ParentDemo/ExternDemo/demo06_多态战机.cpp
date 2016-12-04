#include "iostream"
using namespace std;
class HeroFighter{
public:
	virtual	int AttachPower(){
		return 10;
	}
};
class EnemyFighter{
public:
	int DestoryPower(){
		return 15;
	}
};
class HeroAdv2Fighter:public HeroFighter{
public:
	int AttachPower(){
		return 20;
	}
};

void ObjFighter(HeroFighter *pBase,EnemyFighter *enemy){
	if(pBase->AttachPower()>enemy->DestoryPower()){
		printf("主角赢了\n");
	}else{
		printf("主角挂了\n");
	}
}
void main06(int argc,char *argv[])
{
	HeroFighter h1;
	EnemyFighter e1;
	HeroAdv2Fighter h2;
	ObjFighter(&h1,&e1);
	ObjFighter(&h2,&e1);
	cout<<"hello,world!"<<endl;
	system("pause");
}