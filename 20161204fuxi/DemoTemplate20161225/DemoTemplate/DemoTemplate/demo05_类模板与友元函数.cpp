#include "iostream"
using namespace std;
template<typename T>
class Complex
{
public:
	Complex(T r=0,T i=0);
	Complex(T a)
	{
		Real=a;
		Image=0;
	}
	inline void print() const;
	inline friend Complex operator+ (const Complex<T> & c1,const Complex<T> & c2)
	{
		T r=c1.Real+c2.Real;
		T i=c1.Image+c2.Image;
		return Complex<T>(r,i);
	}
	//friend Complex operator- (const Complex<T> & c1,const Complex<T> & c2);
	//friend Complex operator- (const Complex<T> & c);
private:
	T Real,Image;
};
template<typename T>
Complex<T>::Complex(T r,T i)
{
	Real=r;
	Image=i;
}
/*
template<typename T>
Complex<T> operator+ (const Complex<T> & c1,const Complex<T> & c2)
{
T r=c1.Real+c2.Real;
T i=c1.Image+c2.Image;
return Complex<T>(r,i);
}
*/
template<typename T>
void Complex<T>::print() const
{
	cout<<"( " <<Real<<", "<<Image<<")"<<endl;

}
void main(int argc,char *argv[])
{
	cout<<"hello,world!"<<endl;

	Complex<double> c1(2.5,3.7);
	Complex<double> c2(3.6,7.8);
	Complex<double> c=c1+c2;

	/*c=c1-c2;
	c.print();
	*/
	//c=c1+c2;
	c.print();

	system("pause");
}