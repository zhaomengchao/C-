#include <iostream>
#define PI 3.14
using namespace std;

class point
{
	private:
		int x,y;
	
	public:
		point(int x=0,int y=0)
		{
			this->x=x;
			this->y=y;
		}
		void show()
		{
			
			cout<<"point("<<x<<","<<y<<")"<<endl;
		}
		
};

class Circle :public point
{
	protected:
		double radius;
	public:
		Circle(double r=0,int x=0,int y=0) :point(x,y)
		{
			radius=r;
			cout<<"radius"<<radius<<endl;
			Circle::area1();
		}
		void area1()
		{
			double a;
			a=(PI*(radius*radius));
			cout<<"圆的面积为："<<a<<endl; 
		}
		void show()
		{
			point::show();
		}
};

class Rectangle :public point
{
	protected:
		int length,width;
	public:
		Rectangle(int l=0,int w=0,int x=0,int y=0) :point(x,y)
		{
			length=l;
			width=w;
			cout<<"length "<<length<<endl;
			cout<<"width "<<width<<endl;
			Rectangle::area2();
		}
		void area2()
		{
			int s;
			s=(length*width);
			cout<<"长方形的面积为："<<s<<endl; 
		}
		void show()
		{
			point::show();
		}
		
		
};



int main() {
	point p1(10,10),*p;
	p=&p1;
	p->show();
	Circle c1(10,10,20);
	p=&c1;
	p->show();
	
	Rectangle r1(10,20,30,40);
	p=&r1;
	p->show();
	return 0;
}
