//保证发出去的邮件，大家收到的都不是自己的出现次数

// write your code here cpp
#include<iostream>

using namespace std;

long int help(int n)
{
    if(n < 2)
        return 0;
    if(n  == 2)
        return 1;
    if(n == 3)
        return 2;
    return (n-1)*(help(n-1) + help(n-2));
}

int main()
{
    int n;
    while(cin >> n)
    {
        int count = 0;
        cout << help(n) << endl;
    }
    return 0;
}
