/*
买卖股票的最佳时机含手续费
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
思路：
我们维护一个二维数组dp[n] [2]，也就是n行2列

行数为i代表第i天
第0列代表前i-1天没有股票或者在第i天卖出了股票
第1列代表前i-1天持有股票或者在第i天买入了股票
第1天的情况需要初始化

在第i天，我们根据前一天，第i-1天的状态来更新两个变量，其中卖出需要手续费


dp[i][0] = Math.max(dp[i-1][1]+prices[i],dp[i-1][0]
dp[i][1] = Math.max(dp[i-1][0]-prices[i]-fee,dp[i-1]

*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if(n <= 1)
            return 0;
        // 第二维的 0 表示当前持有的现金（cash）， 1 表示当前持有的股票（stock）   
        vector<vector<int>> dp(n, vector<int> (2));
        // 初始化
        dp[0][0] = 0;
        dp[0][1] = -prices[0];  // 买入的股票
        for(int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], prices[i] + dp[i - 1][1] - fee);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0]; 
    }
};

