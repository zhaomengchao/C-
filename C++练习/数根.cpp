//树根
数根可以通过把一个数的各个位上的数字加起来得到。如果得到的
数是一位数,那么这个数就是数根;如果结果是两位数或者包括更
多位的数字,那么再把这些数字加起来。如此进行下去,直到得到
是一位数为止。
比如,对于24来说,把2和4相加得到6,由于6是一位数,因此6
是24的数根。
再比如39,把3和9加起来得到12,由于1不是一位数,因此还得
把1和2加起来,最后得到3,这是一个一位数,因此3是39的数
根。
现在给你一个正整数,输出它的数根。


#include<iostream>
#include<string>
using namespace std;

int judge_data(int n)
{
    while(n > 9)
    {
        n = n % 10 + n / 10;
    }
    return n;
}

int main()
{
    string s;
    while(cin >> s)
    {
        int sum = 0;
        for(int i = 0; i < s.size(); i++)
        {
            sum += s[i] - '0';
        }
        int n = judge_data(sum);
        cout << n << endl;
    }
    
    return 0;
}