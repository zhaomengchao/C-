/*
�� k ����
��Щ����������ֻ�� 3��5��7�������һ���㷨�ҳ��� k ������ע�⣬���Ǳ�������Щ�����ӣ����Ǳ��벻���������������ӡ����磬ǰ��������˳��Ӧ���� 1��3��5��7��9��15��21��
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