

//输入: "Hello"
//输出: "hello"

//输入: "here"
//输出: "here"

//输入: "LOVELY"
//输出: "lovely"

class Solution {
public:
    string toLowerCase(string str) {
        string s;
        for(int i = 0; i < str.size();i++)
        {
            if(str[i] >= 'A' && str[i] <= 'Z')
            {
                s.push_back(str[i] + 32);
            }
            else
            {
                s.push_back(str[i]);
            }
            
        }
        return s;
    }
};
