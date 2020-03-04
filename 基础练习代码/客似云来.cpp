//客似云来，
//吃过一次早餐就会天天来，连续吃过两天后，接下来每一天都会带一位来吃
//1 1 2 3 5 ......

#include<iostream>

using namespace std;

//注意范围
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