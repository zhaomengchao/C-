//字符串通配符

#include <iostream>
#include <string>
using namespace std;
bool match(const char* pattern, const char *str)
{
    if (*pattern == '\0' && *str == '\0')//如果统配完毕，字符串相等返回真
        return true;
    if (*pattern == '\0' || *str == '\0')
        return false;
    if (*pattern == '?')//匹配一个字符
    {
        return match(pattern + 1, str + 1);
    }
    else if (*pattern == '*')//*可以通配
    {
        // 匹配0个1个或多个
        return match(pattern + 1, str) || match(pattern + 1, str + 1) || match(pattern, str + 1);
    }
    else if (*pattern == *str)
    {
        return match(pattern + 1, str + 1);
    }
 
    return false;
}
int main()
{
    string pattern, str;
    while (cin >> pattern >> str)
    {
        bool ret = match(pattern.c_str(), str.c_str());
        if (ret)
        {
            cout << "true" << endl;
        }
        else
        {    
            cout << "false" << endl;
        }
    }
    return 0;
}