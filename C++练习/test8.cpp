//字符串中找连续最长的数字串
//abcd123sdf123456
//123456
#include<iostream>
#include<string>

using namespace std;
int main()
{
    string str;//存储数据字符串
    string str1;//临时存储数字
    string maxnum;//最长存储
    getline(cin,str);
    int size = str.size();
    
    for(int i = 0; i <= size; i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            str1 += str[i];//存储数字字符
        }
        //读到非数字时，判断当前是否为最长
        else
        {
            if(str1.size() > maxnum.size())
            {
                maxnum = str1;//如果是，就把它给maxnum;
            }
            else
                str1.clear();//否则清空str1
        }
    }
    cout << maxnum <<endl;
    return 0;
}