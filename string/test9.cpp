完全数
例如：28 约数为 1 2 4 7 14  28
1+2+4+7+14 = 24

#include<iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int count = 0;
        for(int i = 3; i <= n;i++)
        {
            int sum = 0;
            for(int j = 1; j < i;j++)
            {
                if(i % j == 0)
                {
                    sum += j;
                }
            }
            if(sum == i)
            {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;


