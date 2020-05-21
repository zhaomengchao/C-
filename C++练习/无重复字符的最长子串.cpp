/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int start = 0;
        int end = 0;
        int count = 0;
        int max = 0;
        
       while(end < n)
       {
           int res = s[end];

           for(int i = start;i < end; i++)
           {
               if(s[i] == res)
               {
                   start = i + 1;
                   count  = end - start;
                   break;
               }
           }

           count++;
           end++;

           if(max < count)
           {
               max = count;
           }
       }
       return max;

    }
};