/*
 ��ΪK��������
����һ�����������һ������ k������Ҫ�ҵ��������к�Ϊ k ��������������ĸ�����

����:nums = [1,1,1], k = 2
���: 2 , [1,1] �� [1,1] Ϊ���ֲ�ͬ�������
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
