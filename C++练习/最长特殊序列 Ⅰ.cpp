/*
最长特殊序列 Ⅰ
https://leetcode-cn.com/problems/longest-uncommon-subsequence-i/
给你两个字符串，请你从这两个字符串中找出最长的特殊序列。

「最长特殊序列」定义如下：该序列为某字符串独有的最长子序列（即不能是其他字符串的子序列）。
*/
class Solution {
public:
    int findLUSlength(string a, string b) {
        int len1 = a.size();
        int len2 = b.size();

        if(len1 == len2)
        {
            if(a == b)
            {
                return -1;
            }
            else
            {
                return len1;
            }
        }
        else
        {
            return len1 > len2 ? len1 : len2;
        }
    }
};