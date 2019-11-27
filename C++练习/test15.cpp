//有一只兔子,从出生后第3个月起每个月都生一只兔子,小兔子长
到第三个月后每个月又生一只兔子,假如兔子都不死,问每个月的
兔子总数为多少?
★★
统计出兔子总数。
@param monthCount第几个月
@return兔子总数
*
 public static int getTotalCount(int monthCount)
 return;

//相当于斐波那契数列
//f(n) = f(n-1) + f(n - 2)
//n 要大于三
//0 1 1 2 3 5 8 13 21 34
#include<iostream>
using namespace std;

int count(int n)
{
    int sum = 0;
    if(n == 1)
    {
        sum = 1;
    }
    else if(n == 2)
    {
        sum = 1;
    }
    else if(n == 3)
    {
        sum = 2;
    }
    else
    {
        sum += count(n - 1) + count(n - 2);
    }
    return sum;
}

int main()
{
    int n;
    while(cin >> n)
    {
        cout << count(n) << endl;
    }
    return 0;
}