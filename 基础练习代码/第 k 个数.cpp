/*
第 k 个数
有些数的素因子只有 3，5，7，请设计一个算法找出第 k 个数。注意，不是必须有这些素因子，而是必须不包含其他的素因子。例如，前几个数按顺序应该是 1，3，5，7，9，15，21。
https://leetcode-cn.com/problems/get-kth-magic-number-lcci/

*/
class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<int> dp(k,0);
        dp[0]=1;
        int p3=0,p5=0,p7=0;
        for(int i=1;i<k;i++){
            dp[i] =min( min(dp[p3]*3,dp[p5]*5),dp[p7]*7);
            if ( dp[p3]*3==dp[i]) 
                p3++;
            if( dp[p5]*5==dp[i])
                p5++;
            if ( dp[p7]*7==dp[i])
                p7++;
        }
        return dp[k-1];

    }
};