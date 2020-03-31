/*
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
数组中某些数字是重复的，但不知道有几个数字重复了，也不知道
每个数字重复了几次。请找出数组中任意一个重复的数字。
*/
class Solution {
public:
//存入amp中
    int findRepeatNumber(vector<int>& nums) {
        map<int,int> m;
        
        for(int i = 0; i < nums.size();i++)
        {
            if(m.find(nums[i]) != m.end())
            {
                return nums[i];//扎到返回
            }
            m[nums[i]] = 1;
        }
        return 0;
    }
};