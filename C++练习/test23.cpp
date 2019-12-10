class Solution {
public:
    /**
     *    正数数组中的最小不可组成和
     *    输入：正数数组arr
     *    返回：正数数组中的最小不可组成和
     */
    int getFirstUnFormedNum(vector<int> arr, int len) {
        int sum = 0, min = arr[0];
        int i, j;
        for (int i = 0; i < len; ++i) {
            sum += arr[i];
            min = arr[i] < min ? arr[i] : min;
        }
        vector<int> dp(sum + 1, 0);
        for (i = 0; i < len; ++i) {
            for (j = sum; j >= arr[i]; --j) {
                if (dp[j] < dp[j - arr[i]] + arr[i]) // 对每个承重计算当前最大能放置重量
                    dp[j] = dp[j - arr[i]] + arr[i]; // 更新背包中能够放入的最大值
                else
                    dp[j] = dp[j];
            }
        }
        // 最后当承重为n时，放入的重量不为n则认为是最大不可求和
        for (i = min; i <= sum; ++i) {
            if (i != dp[i])
                return i;
        }
        return sum + 1;
    }
};