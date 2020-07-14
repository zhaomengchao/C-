/*
https://leetcode-cn.com/problems/compress-string-lcci/
字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。
比如，字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回原先的字符串。
你可以假设字符串中只包含大小写英文字母（a至z）。

示例1:

 输入："aabcccccaaa"
 输出："a2b1c5a3"
*/
class Solution {
public:
    string compressString(string S) {
        if ((int)S.length() == 0) return S; // 空串处理
        string ans = "";
        int cnt = 1;
        char ch = S[0];
        for (int i = 1; i < (int)S.length(); ++i){
            if (ch == S[i]) cnt++;
            else{
                ans += ch + to_string(cnt); // 注意 cnt 要转为字符串
                ch = S[i];
                cnt = 1;
            }
        }
        ans += ch + to_string(cnt);
        return ans.length() >= S.length() ? S : ans;
    }
};