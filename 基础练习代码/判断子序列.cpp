/*

给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
示例 1:
s = "abc", t = "ahbgdc"

返回 true.
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        int m = s.size(), n = t.size();
        while(i < m && j < n){
            if(s[i] == t[j]){
                i++;
                j++;
            }
            else j++;
        }
        return i == m;
    }
};
