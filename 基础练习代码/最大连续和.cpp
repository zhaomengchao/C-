//最大连续和
#include<iostream>
#include<vector>
using namespace std;

int getMax(vector<int> v1)
{
    int tmp = 0;
    int ret = v1[0];
    int result = v1[0];
    for(int i = 0; i < v1.size();i++)
    {
        tmp += v1[i];
        if(ret < tmp)
        {
            ret = tmp;
        }
        if(tmp < 0)
        {
            tmp = 0;
        }
        result = max(result,ret);
    }
    return result;
}

int main()
{
    vector<int> v;
    int n = 0;
    cin >> n;
    while(n--)
    {
        int tmp = 0;
        cin >> tmp;
        v.push_back(tmp);
    }
    
    cout << getMax(v) << endl;
    
    return 0;
}