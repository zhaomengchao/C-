/*���ӣ�https://www.nowcoder.com/questionTerminal/b388bdee5e3e4b1c86a79ad1877a3aa4*/


#include <iostream>
#include <math.h>
using namespace std;
struct fraction
{
	//����
    long long up,down;
};
	long long gcd(long long a,long long b)
	{
		//�����Լ��
		if(b==0)
			return a;
		else 
			return gcd(b,a%b);
	}
	fraction reduction(fraction result)
	{
		//����
		if(result.down<0)
		{
			//ʹ��ĸ�Ǹ�
			result.up=-result.up;
			result.down=-result.down;
		}
		if(result.up==0)
			result.down=1;
		else{
			long long d=gcd(abs(result.up),abs(result.down));   //Լ��
			result.up/=d;
			result.down/=d;
			}
			return result;
	}
	fraction add(fraction a,fraction b)
	{
		//�����ӷ�����
		fraction result;
		result.up=a.up*b.down+b.up*a.down;
		result.down=a.down*b.down;
		return result;
		
	}
	fraction minu(fraction a,fraction b)
	{
		fraction result;
		result.up=a.up*b.down-b.up*a.down;
		result.down=a.down*b.down;
		return result;
		
	}
	fraction multi(fraction a,fraction b)
	{    
		fraction result;
		result.up=a.up*b.up;
		result.down=a.down*b.down;
		return result;
	}
	fraction divide(fraction a,fraction b)
	{
		fraction result;
		result.up=a.up*b.down;
		result.down=a.down*b.up;
		return result;
	}
	void printresult(fraction a)
	{
		//���
		a=reduction(a);
		if(a.up<0)
			cout<<"(";    if(a.down==1) cout<<a.up;  //���� 
		else if(abs(a.up)>a.down)  //�ٷ�����Ϊ������
			cout<<a.up/a.down<<" "<<abs(a.up)%a.down<<"/"<<a.down;
		else
			cout<<a.up<<"/"<<a.down; //�����
		if(a.up<0) cout<<")";
	}
	int main()
	{
		fraction a,b;
		scanf("%lld/%lld %lld/%lld",&a.up,&a.down,&b.up,&b.down);
		printresult(a);cout<<" + ";
		printresult(b);cout<<" = ";
		printresult(add(a,b));
		cout<<'\n';    printresult(a);
		cout<<" - ";printresult(b);
		cout<<" = ";printresult(minu(a,b));
		cout<<'\n';    printresult(a);
		cout<<" * ";printresult(b);
		cout<<" = ";printresult(multi(a,b));
		cout<<'\n';    printresult(a);
		cout<<" / ";printresult(b);
		cout<<" = ";
		if(b.up==0)
			cout<<"Inf"<<'\n';
		else
		{
			printresult(divide(a,b));
			cout<<'\n';
		}
        
	return 0;
	}