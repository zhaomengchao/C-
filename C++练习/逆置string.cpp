
//i  like  bao.
//bao. like i

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    //先反转字符串
    reverse(s.begin(),s.end());
    
    //反转单词
    
    auto start = s.begin();
    while(start != s.end())
    {
        auto end = start;
        while(end != s.end() && *end != ' ')
        {
            end++;
        }
        reverse(start,end);
        
        if(end != s.end())
        {
            start = end + 1;
        }
        else
        {
            start = end;
        }
    }
    cout << s << endl;
    
    return 0;
}
