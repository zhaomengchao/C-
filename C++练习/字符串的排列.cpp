/*输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;
        for (auto &c: s1) mp[c]++; // 记录 出现次数的差值

        int l = 0, r = 0;
        while (r < s2.size()){
            char c = s2[r++];
            mp[c]--; // 入窗
            while (l < r && mp[c] < 0){ // 出窗
                mp[s2[l++]] ++;
            }
            if (r - l == s1.size()) return true;
        }
        return false;
    }
};

