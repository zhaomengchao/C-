//有一个数组有N个元素，求连续子数组的最大和
//[1 2 -1]
//3
#include<iostream>

using namespace std;
#include<vector>

int get_Max(vector<int> v1,int len)
{
    if(len == 0)
    {
        return 0;
    }
    int sum = 0;
    int count = -1;
    
    for(int i= 0; i < len;i++)
    {
        if(sum <= 0)
        {
            sum =v1[i];
        }
        else
        {
            sum += v1[i];
        }
        if(sum > count)
        {
            count = sum;
        }
            
    }
    return count;
}
int main()
{
    vector<int> v1;
    int n = 0;//元素个数
    cin >> n;
    int tmp = 0;
    for(int i = 0; i < n;i++)
    {
        cin >> tmp;
        v1.push_back(tmp);
    }
    cout << get_Max(v1,n);
    return 0;
}