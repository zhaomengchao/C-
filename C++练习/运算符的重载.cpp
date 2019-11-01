#include <iostream>

using namespace std;

class fraction
{
	public:
		fraction(int a=0,int b=1)
		{
			above=a;
			below=b;
		} 
		fraction operator+(fraction);
		fraction operator-(fraction);
		fraction operator*(fraction);
		fraction operator/(fraction);
		void dispaly();
		void input();
	private:
		int above;
		int below;
	
};

fraction fraction::operator+(fraction f)
{
	fraction p;
	p.above=above*f.below+f.above*below;
	p.below=below*f.below;
	
	cout<<above*f.below+f.above*below<<endl<<"--"<<endl<<below*f.below<<endl; 
	return p;
}
fraction fraction::operator-(fraction f)
{
	fraction p;
	p.above=above*f.below-f.above*below;
	p.below=below*f.below;
	cout<<above*f.below-f.above*below<<endl<<"--"<<endl<<below*f.below<<endl;
	return p;
}
fraction fraction::operator*(fraction f)
{
	fraction p;
	p.above=above*f.above;
	p.below=below*f.below;
	
	cout<<above*f.above<<endl<<"--"<<endl<<below*f.below<<endl;
	return p;
}
fraction fraction::operator/(fraction f)
{
	fraction p;
	p.above=above*f.below;
	p.below=f.above*below;
	
	cout<<above*f.below<<endl<<"--"<<endl<<f.above*below<<endl;
	return p;
}
void fraction::dispaly()
{
	cout<<above<<endl<<"--"<<endl<<below<<endl;
}
void fraction::input()
{
	cout<<"请输入分子：";
	cin>>above;
	while(true)
	{
		cout<<"请输入分母：";
		cin>>below;
		if(below==0)
		{
			cout<<"分母不能为零："; 
		}
		else
			break;
	}
	
	 
}
int main()
{
	fraction f1(10,20),f2(30,50);
	f1.input();
	f2.input();
	f1.dispaly();
	f2.dispaly();
	cout<<"分数的加法："<<endl;
	f1.operator+(f2);
	cout<<"分数的减法："<<endl;
	f1.operator-(f2);
	cout<<"分数的乘法："<<endl;
	f1.operator*(f2);
	cout<<"分数的除法："<<endl;
	f1.operator/(f2);
	return 0;
}
