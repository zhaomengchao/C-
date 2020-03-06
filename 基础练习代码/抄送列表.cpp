/*抄送列表*/
/*第一行，姓名之间用逗号隔开，如果姓名中包含空格或者都好，用双引号包含起来
第二行输入一个姓名，是带查找用户的姓名，
如果第一行出现第二行人的姓名，则输出，Ignore
否则输出Important!
*/

// write your code here cpp
#include<iostream>
#include<string>

using namespace std;

int main()
{
    
    string s1, s2;
    while(getline(cin , s1) && getline(cin , s2))
    {
        bool flag = false;
        for(size_t i = 0; i < s1.size();i++)
        {
            string ret;//存储单个的名字
            if(s1[i] == '"')//找出双引号内的名字
            {
                i++;
                while(i < s1.size() && s1[i] != '"')//存入到ret中进行保存
                {
                    ret += s1[i];
                    i++;
                }
                if(ret == s2)//与s2进行比较
                {
                    flag = true;
                    break;
                }
            }
            else if(s1[i] != ',')
            {
                while(i < s1.size() && s1[i] != ',')
                {
                    ret += s1[i];
                    i++;
                }
                if(ret == s2)
                {
                    flag = true;
                    break;
                }
            }
        }
        if(flag == true)
        {
            cout << "Ignore" << endl;
        }
        else
        {
            cout << "Important!" << endl;
        }
    }
    return 0;
}