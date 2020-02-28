//Ìæ»»¿Õ¸ñ
class Solution {
public:
    string replaceSpace(string s) {
        string s1;
        for(auto c : s)
        {
            if(c == ' ')
                s1 += "%20";
            else
                s1 += c;
        }
        return s1;
    }
};