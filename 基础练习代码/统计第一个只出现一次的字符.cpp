//统计第一个只出现一次的字符 map
class Solution {
public:
    char firstUniqChar(string s) {
        if(s == "")
        {
            return ' ';
        }
        map<char, int> m;
        for(auto i = 0; i < s.size(); i++)
        {
            m[s[i]]++;
        }

        for(auto i = 0;i < s.size();i++)
        {
            if(m[s[i]] == 1)
                return s[i];
        }
        return ' ';
    }
};