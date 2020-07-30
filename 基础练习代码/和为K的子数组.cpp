/*
 和为K的子数组
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
https://leetcode-cn.com/problems/subarray-sum-equals-k/
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for (int start = 0; start < nums.size(); ++start) {
            int sum = 0;
            for (int end = start; end >= 0; --end) {
                sum += nums[end];
                if (sum == k) {
                    count++;
                }
            }
        }
        return count;
    }
};
