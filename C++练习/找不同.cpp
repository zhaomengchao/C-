/*
字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。

请找出在 t 中被添加的字母。
输入：
s = "abcd"
t = "abcde"

输出：
e

解释：
'e' 是那个被添加的字母。
*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        for(int i = 0; i < s.size();i++)
        {
            res ^= s[i];
        }
        for(int j = 0; j < t.size();j++)
        {
            res ^= t[j];
        }
    return res;
    }
};