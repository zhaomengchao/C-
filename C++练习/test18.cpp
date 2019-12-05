//如果猫身长小于容器的周长，那么输出Yes

#include<iostream>
#include<string>
using namespace std;

int main()
{
    double n,r;
    double pi = 3.14;
    while(cin >> n >> r)
    {
        double C = 2*pi*r;
        if(C >= n)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}