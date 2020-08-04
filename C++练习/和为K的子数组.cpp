/*
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :

输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。

链接：https://leetcode-cn.com/problems/subarray-sum-equals-k

*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, ans = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(int i: nums){
            sum += i;
            if(mp.find(sum-k) != mp.end()) ans += mp[sum-k];
            mp[sum] ++;
        }
        return ans;
    }
};
