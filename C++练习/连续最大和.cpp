//连续最大和
#include<iostream>
#include<vector>

using namespace std;

int MAX_arr_Sum(vector<int>& res)
{
    int sum1 = 0;
    int sum2 = 0;
    int max = res[0];
    
    for(size_t i = 0; i < res.size();i++)
    {
        if(sum1 >= 0)
        {
            sum2 = sum1 + res[i];
        }
        else
        {
            sum2 = res[i];
        }
        if(sum2 > max)
        {
            max = sum2;
        }
        if(sum2 < 0)
        {
            sum2 = 0;
        }
        sum1 = sum2;
    }
   
    return max;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(size_t i = 0; i < v.size();i++)
    {
        cin >> v[i];
    }
    
    cout << MAX_arr_Sum(v) << endl;
    return 0;
    
}