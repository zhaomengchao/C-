//链接：https://www.nowcoder.com/questionTerminal/839f681bf36c486fbcc5fcb977ffe432?toCommentId=168854
//两种排序方法

//根据长度排列输出"lexicographically"
//根据长度排列而不是字典序排列输出"lengths"

//1.根据字符串的字典序排序。例如：
//"car" < "carriage" < "cats" < "doggies < "koala"
//2.根据字符串的长度排序。例如：
//"car" < "cats" < "koala" < "doggies" < "carriage"

#include<iostream>
using namespace std;

#include<string>
#include<vector>

bool is_le(vector<string> v1)
{
    int size = v1.size();
    for(int i = 0; i < size - 1;i++)
    {
        if(v1[i] > v1[i + 1])
        {
            return false;
        }
    }
    return true;
}
bool is_len(vector<string> v2)
{
    int size = v2.size();
    for(int i = 0; i < size - 1; i++)
    {
        if(v2[i].length() > v2[i+1].length())
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n = 0;
    while(cin >> n)
    {
        string s1;
        vector<string> v1;
        for(int i = 0; i < n; ++i)
        {
            cin >> s1;
            v1.push_back(s1);
        }
        
        if(is_le(v1) && is_len(v1))
        {
            cout << "both" << endl;
        }
        else if(is_le(v1) && !is_len(v1))
        {
            cout << "lexicographically" << endl;
        }
        else if(!is_le(v1) && is_len(v1))
        {
            cout << "lengths" << endl;
        }
        else{
            cout << "none" << endl;
        }
    }
    return 0;
}