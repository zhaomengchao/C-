��Ŀ����
С�׾���������������Ϸ��һ��,������һ�������������Ϸ����
��ɫ�ĳ�ʼ����ֵΪa.�ڽ�������һ��ʱ������������������n��
����,ÿ������ķ�����Ϊb1,b2,b3.bn.��������Ĺ��������biС
�ڵ���С�׵ĵ�ǰ����ֵc��ô���������ɴ�ܹ��ﲢ��ʹ���Լ�
������ֵ����bi;���bi����c����Ҳ�ܴ�ܹ���,����������ֵֻ��
����bi��c�����Լ����ô��������,��һϵ�еĶ�����,С�׵���
������ֵΪ����?

#include<iostream>
#include<vector>
using namespace std;


int Gcd(int m,int n)
{
    int max = m > n? m:n;
    int min = m > n? n:m;
    for(int i = min; i >= 1; i--)
    {
        if(max % i == 0 && min % i == 0)
        {
            return i;
        }
    }
    return 1;
}

int main()
{
    int n,a = 0;
    int val;
    vector<int> v;
    while(cin >> n >> a)
    {
        while(n--)
       {
           cin >> val;
           v.push_back(val);
       }
       for(int i = 0; i < v.size();i++)
        {
            if(v[i] <= a)
            {
                a += v[i];
            }
            else
            {
                a += Gcd(a,v[i]);
            }

        }
        cout << a << endl;
        v.clear();
    }
    return 0;
}