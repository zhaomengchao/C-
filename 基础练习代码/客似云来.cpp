//����������
//�Թ�һ����;ͻ��������������Թ�����󣬽�����ÿһ�춼���һλ����
//1 1 2 3 5 ......

#include<iostream>

using namespace std;

//ע�ⷶΧ
long fib(int n)
{
    long a = 1;
    long b = 1;
    long c;
    if(n == 1)
    {
        return 1;
    }
    if( n == 2)
    {
        return 1;
    }
    while(n > 2)
    {
        c = a + b;
        a = b;
        b = c;
        n--;
    }
    return c;
}


int main()
{
    int from;
    int to;
    while(cin >> from >> to)
    {
        long long sum = 0;
        for(int i = from; i <= to; i++)
        {
            sum += fib(i);
        }
        cout <<sum << endl;
    }
    return 0;
}