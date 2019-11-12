//统计回文的次数

#include<iostream>
#include<string>
using namespace std;

bool is_pd(string s)
{
    int size = s.size();
    if(size == 1)
    {
        return true;
    }
    int start = 0;
    int end  = size - 1;
    
    while(start <= end)
    {
        if(s[start++] != s[end--])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    
    int count = 0;
    for(int i = 0; i <= s1.size();++i)
    {
        string tmp = s1;
        tmp.insert(i,s2);//每次插入另一个字符串，判断是否为回文
        if(is_pd(tmp))
        {
            count++;
        } 
    }
    cout << count << endl;
    return 0;
}