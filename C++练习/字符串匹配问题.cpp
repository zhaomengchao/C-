/*对于字符串str，其中绝对不含有字符’.’和‘*’。再给定字符串exp，
其中可以含有’.’或’‘*’，’*’字符不能是exp的首字符，并且任意两个’*‘字符不相邻。
exp中的’.’代表任何一个字符，exp中的’*’表示’*‘的前一个字符可以有0个或者多个。
请写一个函数，判断str是否能被exp匹配(注意：输入的数据不保证合法，但只含小写字母和‘.’和‘*’)。*/
#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

bool is_val(string &str, string &exp)
{
    for(int i = 0; i < str.size();i++)
    {
        if(str[i] == '.' || str[i] == '*')
        {
            return false;
        }
    }
    if(exp[0] == '*')
    {
        return false;
    }
    for(int i = 0; i < exp.size();++i)
    {
        if(exp[i] == '*' && exp[i+1] == '*')
        {
            return false;
        }
    }
    return true;
}

bool isMatch(string &str, string &exp, int si, int ei)
{
    //递归出口
    if(ei == static_cast<int>(exp.size())){
        return si == static_cast<int>(str.size());
    }
     
    if(ei + 1 == static_cast<int>(exp.size()) || exp[ei + 1] != '*')
    {
        if(si != static_cast<int>(str.size()) && (exp[ei] == str[si] || exp[ei] == '.') )
            return isMatch(str, exp, si + 1, ei + 1);
        else return false;
    }else if(ei + 1 != static_cast<int>(exp.size()) && exp[ei + 1] == '*'){
        if(si != static_cast<int>(str.size()) && (str[si] != exp[ei] && exp[ei] != '.'))
            return isMatch(str, exp, si, ei + 2);
        else{
            while(si != static_cast<int>(str.size()) && (str[si] == exp[ei] || exp[ei] == '.')){
                if(isMatch(str, exp, si + 1, ei + 2)) return true;
                si++;
            }
        }
    }
}
int main()
{
    string str;
    string exp;
    getline(cin , str);
    getline(cin , exp);
    
    if(is_val(str,exp) == false)
    {
        cout << "NO" << endl;
        return 0;
    }
    
    bool ret = isMatch(str,exp,0,0);
    if(ret)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout <<"NO" << endl;
    }
    return 0;
}