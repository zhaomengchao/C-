//ͳ�Ƶ�һ��ֻ����һ�ε��ַ� map
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