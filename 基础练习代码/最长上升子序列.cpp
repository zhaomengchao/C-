//输入：1 7 3 5 9 4 8 
//输出：4
//升序子序列：（1 7）（1 3 5 9）（1 3 4 8）

// write your code here cpp
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    
    while(cin >> n)
    {
        vector<int> v(n,0);
        vector<int> ret(n,1);
        for(int i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        int result = 1;
        for(int i = 1; i < n;i++)
        {
            for(int j = 0; j < i;j++)
            {
                if(v[i] > v[j])
                    ret[i] = max(ret[i],ret[j] + 1);
            }
            result = max(result,ret[i]);
        }
         cout << result << endl;
    }
    
   
    return 0;
}