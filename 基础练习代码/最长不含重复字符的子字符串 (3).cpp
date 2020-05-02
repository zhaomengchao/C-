//请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int ret = 0, l = 0, r = 0;
        while (r < s.size()) {
            if (m.find(s[r]) != m.end()) {
                l = max(l, m[s[r]] + 1);
            }
            m[s[r++]] = r;
            ret = max(r - l, ret);
        }
        return ret;
    
    }
};