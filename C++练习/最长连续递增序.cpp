/*
674. 最长连续递增序列
给定一个未经排序的整数数组，找到最长且连续的的递增序列，并返回该序列的长度。

 

示例 1:

输入: [1,3,5,4,7]
输出: 3
解释: 最长连续递增序列是 [1,3,5], 长度为3。
尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为5和7在原数组里被4隔开。 
https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/
*/
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()==0)  return 0;
        int res=1;
        int temp=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
                temp++;
            else if(nums[i]<=nums[i-1])
                temp=1;
            res=max(res,temp);
        }
        return res;
    }
};