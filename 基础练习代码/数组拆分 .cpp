//给定长度为2n的数组, 你的任务是将这些数分成n 对,
//例如 (a1, b1), (a2, b2), ..., (an, bn) ，使得从1 到n 的 min(ai, bi) 总和最大。

//输入: [1,4,3,2]

//输出: 4
//解释: n 等于 2, 最大总和为 4 = min(1, 2) + min(3, 4).

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sum = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size()-1;i += 2)
        {
            if(nums[i] < nums[i + 1])
            {
                sum += nums[i];
            }
            else
            {
                sum += nums[i+1];
            }
        }
        return sum;
    }
};