//在字符串中找出数字密码
// write your code here cpp、
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s1;
    while(getline(cin , s1))
    {
        string tmp;
        for(int i = 0; i < s1.size();i++)
        {
            if(s1[i] >= '0' && s1[i] <= '9')
            {
                tmp.push_back(s1[i]);
            }
        }
        
        for(int i = 0; i < tmp.size();i++)
        {
            cout << tmp[i];
        }
        cout << endl;
    }
    return 0;
}