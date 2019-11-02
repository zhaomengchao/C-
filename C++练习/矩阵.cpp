#include <iostream>
#include<stdlib.h>
using namespace std;

class Rectangle
{
	public:
		Rectangle(int l=0,int t=0,int r=0,int b=0 );
		~Rectangle(){
		};//析构函数 
		void Assign(int l,int t,int r,int b);
		void Setleft(int t){
			left=t;
		}
		void Setright(int t){
			right=t;
		}
		void Settop(int t){
			top=t;
		}
		void Setbottom(int t){
			bottom=t;
		}
		void show();
		int length();
		int width();
		int perimeter();
		int area();
		bool isSquare();
	private:
		int left, top;
		int right, bottom;
			
};

Rectangle::Rectangle(int l,int t,int r,int b)
{
	left=l;
	top=t;
	right=r;
	bottom=b;
}
void Rectangle::Assign(int l,int t,int r,int b)
{
	left=l;
	top=t;
	right=r;
	bottom=b;
}
void Rectangle::show()
{
	cout<<"left-top is("<<left<<","<<top<<")"<<endl;
	cout<<"rigth-bottom is("<<right<<","<<bottom<<")"<<endl;
}
int Rectangle::length()
{
	int a;
	a=right-left;
	cout<<"长度为："<<a<<endl;
	return a; 
}
int Rectangle::width()
{
	int c;
	c=top-bottom;
	cout<<"宽度为："<<c<<endl;
	return c; 
}
int Rectangle::area()
{
	int s;
	s=(right-left)*(top-bottom);
	cout<<"面积为："<<s<<endl;
	return s;
}
int Rectangle::perimeter()
{
	int z;
	z=((right-left)+(top-bottom))*2;
	cout<<"周长为："<<z<<endl;
	return z;
}
bool Rectangle::isSquare()
{
	if((right-left)==(top-bottom))
	{
		cout<<"此矩形为正方形"<<endl; 
	}
	else
	{
		cout<<"为一般矩形"<<endl; 
	}
}
int main() {
	Rectangle p;
	p.show();
	p.Assign(5,10,10,5);

	p.show();
	p.length();
	p.width();
	p.area();
	p.perimeter();
	p.isSquare();
	return 0;
}
