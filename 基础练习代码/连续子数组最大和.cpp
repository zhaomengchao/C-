/*连续子数组最大和，sum1 如果数组中的连续数相小于0，则跳转到下一个位置继续计算，sum 用于存储最大值*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int sum1 =0;
        for(int i = 0; i < nums.size();i++)
        {
            if(sum1 <= 0)
            {
                sum1 = nums[i];
            }
            else
            {
                sum1 += nums[i];
            }
            if(sum < sum1)
            {
                sum = sum1;
            }
        }
        return sum;
    }
};