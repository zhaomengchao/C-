3  1
12  3 
0   0

#include<iostream>

using namespace std;
int main()
{
    int n;
    while(cin >> n && n)
    {
        int count = 0;
        while(n > 1)
        {
            n = n /3 + 1 - (n % 3 ^ 3)/3;
            count++;
        }
        cout << count << endl;
    }
    return 0;
}