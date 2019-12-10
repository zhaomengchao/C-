class Solution {
public:
    /**
     *    ���������е���С������ɺ�
     *    ���룺��������arr
     *    ���أ����������е���С������ɺ�
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
                if (dp[j] < dp[j - arr[i]] + arr[i]) // ��ÿ�����ؼ��㵱ǰ����ܷ�������
                    dp[j] = dp[j - arr[i]] + arr[i]; // ���±������ܹ���������ֵ
                else
                    dp[j] = dp[j];
            }
        }
        // ��󵱳���Ϊnʱ�������������Ϊn����Ϊ����󲻿����
        for (i = min; i <= sum; ++i) {
            if (i != dp[i])
                return i;
        }
        return sum + 1;
    }
};