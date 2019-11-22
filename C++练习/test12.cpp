//跳石板
//通过率80
#include<iostream>
using namespace std;


int Search_step(int n, int m)
{
    if(n > m)
    {
        return -1;
    }
    if(n == m)
    {
        return 0;
    }
    int res = 0;
    for(int i = 2; i < n; i++)
    {
        if(i*(n/i) == n)
        {
            res++;
            if(Search_step(n+n/i,m) != -1)
            {
                res += Search_step(n + n/i,m);
                return res;
            }
            else{
                res--;
            }
        }
    }
    return -1;
    
}

int main()
{
    int N,M;
    while(cin >> N >> M)
    {
        cout << Search_step(N,M)<<endl;
    }
    return 0;
}