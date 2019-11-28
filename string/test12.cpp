//查找两个字符串中最长的公共子串
题目描述
查找两个字符串a,b中的最长公共子串。若有多个,输出在较短串中
最先出现的那个。
输入描述:
输入两个字符串
输出描述:
返回重复出现的字符
示例1输入输出示例仅供调试,后台判题数据般不包含示例
输入
 abcdefghijklmnop
 abcsafjklmnopgrstuvw
输出
 jklmnop

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1;
    string s2;
    while(cin >> s1 >> s2)
    {
        if(s1.size() > s2.size())//先找最长公共子串
        {
            swap(s1,s2);
        }
        string str;//存储字串
        string tmp;
        for(int i = 0; i < s1.size(); i++)
        {
            for(int j = i;j < s1.size();j++)
            {
                tmp = s1.substr(i,j-i+1);//string substr (size_t pos = 0, size_t len = npos) const;从第一个元素开始找len个长度的子串
                if(int (s2.find(tmp)) < 0)//然后在s2中找相应的子串
                {
                    break;
                }
                else if(str.size() < tmp.size())//把每一次找到的子串与前一个找到的字串去比较长度，大的交换小的不变
                {
                    str = tmp;
                }
            }
        }
        cout << str << endl；
    }
    return 0;
}