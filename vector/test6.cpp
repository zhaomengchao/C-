//给定一个长度为偶数的数组arr，将该数组中的数字两两配对并求和，
//在这些和中选出最大和最小值，请问该如何两两配对，才能让最大值和最小值的差值最小？
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
 
int main()
{
    int length;
    vector<int > nums;
    while(cin>>length)
    {
        int input;
        while(cin>>input)
            nums.push_back(input);
        sort(nums.begin(),nums.end());
        int max = INT_MIN,min = INT_MAX;
        int i = 0,j = nums.size()-1;
        while(i<j)
        {
            int sum = nums[i]+nums[j];
            if(sum>max)    max = sum;
            if(sum<min)    min = sum;
            i++;j--;
        }
        cout<<(max-min)<<endl;
          
    }
    return 0;
}