//三角形 判断任意三条边是否构成三角形
#include<iostream>
using namespace std;

int main()
{
    double a,b,c;
    while(cin >> a >> b >> c)
    {
        if((a + b > c) && (a + c > b) && (c + b > a))
        {
            if(a - b < c && a - c < b && c - b < a)
            {
                cout << "Yes" << endl;
            }
            
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}