解析规则： 

1.参数分隔符为空格 
2.对于用“”包含起来的参数，如果中间有空格，不能解析为多个参数。比如在命令行输入xcopy /s “C:\program files” “d:\”时，参数仍然是4个，第3个参数应该是字符串C:\program files，而不是C:\program，注意输出参数时，需要将“”去掉，引号不存在嵌套情况。
3.参数不定长 
4.输入由用例保证，不会出现不符合要求的输

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    string s;
    vector<string> v;
    while(cin >> s)
    {
        v.push_back(s);
    }
    string s2;
    string s3;
    
    size_t size = v.size();
    cout << size << endl;
    
    for(int i = 0; i < size; i++)
    {
        s2 = v[i];//存取字符串,处理出现一个字符串的情况
        if(s2[0] == '"')
        {
            int a = s2.size();
            for(int j = 1; j < a-1;j++)
            {
                s3[j] = s2[j];//输出时要将“”去掉，所以减去二
            }
           
            cout << s3 << endl;
        }
        else
        {
            cout  << s2 << endl;
        }
    }
  
    return 0;

}