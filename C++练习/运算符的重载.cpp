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
	cout<<"��������ӣ�";
	cin>>above;
	while(true)
	{
		cout<<"�������ĸ��";
		cin>>below;
		if(below==0)
		{
			cout<<"��ĸ����Ϊ�㣺"; 
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
	cout<<"�����ļӷ���"<<endl;
	f1.operator+(f2);
	cout<<"�����ļ�����"<<endl;
	f1.operator-(f2);
	cout<<"�����ĳ˷���"<<endl;
	f1.operator*(f2);
	cout<<"�����ĳ�����"<<endl;
	f1.operator/(f2);
	return 0;
}
