

//����: "Hello"
//���: "hello"

//����: "here"
//���: "here"

//����: "LOVELY"
//���: "lovely"

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
