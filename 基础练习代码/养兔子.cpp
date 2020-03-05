//一只成熟的兔子每天能产下一胎兔子，每只小兔子的成熟期是一天，某人领养一只小兔子，
//请问n天后,还会有多少只小兔子



// write your code here cpp
#include<iostream>
using namespace std;


int main()
{
    int n;
    while(cin >> n)
    {
        if(n <= 3)
        {
            cout << n << endl;
        }
        else
        {
            long a = 2;
            long b = 3;
            long c;
            
            for(int i = 4; i <= n; i++)
            {
                c = a + b;
                a = b;
                b = c;
            }
            cout << c << endl;
        }
    }
    
    return 0;
    
}