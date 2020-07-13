/*
给你一个由若干 0 和 1 组成的字符串 s ，请你计算并返回将该字符串分割成两个 非空 子字符串（即?左 子字符串和 右 子字符串）所能获得的最大得分。

「分割字符串的得分」为 左 子字符串中 0 的数量加上 右 子字符串中 1 的数量。
输入：s = "00111"
输出：5
解释：当 左子字符串 = "00" 且 右子字符串 = "111" 时，我们得到最大得分 = 2 + 3 = 5

链接：https://leetcode-cn.com/problems/maximum-score-after-splitting-a-string
*/
class Solution {
public:
    int maxScore(string s) {

        int n = s.size();
        int left = 0;
        int right = 0;
        
        for(int i = 0; i < n;i++)
        {
            if(s[i] == '1')
            {
                right++;
            }
        }
        //判断首元素
        if(s[0] == '1')
        {
            right--;
        }
        else
        {
            left++;
        }
        int maxsum = 0;
        for(int i = 1; i < s.size();i++)
        {
            maxsum = max(maxsum, right+left);

            if(s[i]=='1')
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return maxsum;
    }
};