//����һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ���
//���������͡�


class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        //����Ѱ�������Сֵ����Ŀ����ʼֵһ��Ҫ����������ϵ���С���ֵ
        int result = INT_MIN;
        int numsSize = int(nums.size());
        //dp[i]��ʾnums����nums[i]��β����������
        vector<int> dp(numsSize);
        dp[0] = nums[0];
        result = dp[0];
        for (int i = 1; i < numsSize; i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            result = max(result, dp[i]);
        }

        return result;
    }
};
