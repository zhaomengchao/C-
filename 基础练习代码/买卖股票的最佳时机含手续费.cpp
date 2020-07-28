/*
������Ʊ�����ʱ����������
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
˼·��
����ά��һ����ά����dp[n] [2]��Ҳ����n��2��

����Ϊi�����i��
��0�д���ǰi-1��û�й�Ʊ�����ڵ�i�������˹�Ʊ
��1�д���ǰi-1����й�Ʊ�����ڵ�i�������˹�Ʊ
��1��������Ҫ��ʼ��

�ڵ�i�죬���Ǹ���ǰһ�죬��i-1���״̬��������������������������Ҫ������


dp[i][0] = Math.max(dp[i-1][1]+prices[i],dp[i-1][0]
dp[i][1] = Math.max(dp[i-1][0]-prices[i]-fee,dp[i-1]

*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if(n <= 1)
            return 0;
        // �ڶ�ά�� 0 ��ʾ��ǰ���е��ֽ�cash���� 1 ��ʾ��ǰ���еĹ�Ʊ��stock��   
        vector<vector<int>> dp(n, vector<int> (2));
        // ��ʼ��
        dp[0][0] = 0;
        dp[0][1] = -prices[0];  // ����Ĺ�Ʊ
        for(int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], prices[i] + dp[i - 1][1] - fee);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0]; 
    }
};

