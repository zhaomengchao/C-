//统计一个正数二进制中一的个数
#include<iostream>
using namespace std;


int main()
{
    int n;
    while(cin >> n)
    {
        int count = 0;
        while(n)
        {
            if(n & 1)
            {
                count++;
            }
            n >>= 1;
        }
        cout << count << endl;
    }
    return 0;
}