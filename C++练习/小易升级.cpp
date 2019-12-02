题目描述
小易经常沉迷于网络游戏有一次,他在玩一个打怪升级的游戏他的
角色的初始能力值为a.在接下来的一段时间内他将会依次遇见n个
怪物,每个怪物的防御力为b1,b2,b3.bn.如果遇到的怪物防御力bi小
于等于小易的当前能力值c那么他就能轻松打败怪物并且使得自己
的能力值增加bi;如果bi大于c那他也能打败怪物,但他的能力值只能
增加bi与c的最大公约数那么问题来了,在一系列的锻炼后,小易的最
终能力值为多少?

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