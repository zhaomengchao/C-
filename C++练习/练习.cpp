#include<iostream>
#include<string>
//输入一个字符串，求出该字符串包含的字符集合
//每组数据输入一个字符串，字符串最大长度为100，且只包含字母，不可能为空串，区分大小写
using namespace std;

int main()
{
    string str;
    while(cin >> str)
    {
        int count[256] = {0};
        
        for(auto ch : str)
        {
            if(count[ch] == 0)
              {
                  cout << ch;
                  count[ch] = 1;
              }
        }
              
            
        cout<<endl;
    }
    return 0;
    
}

//输入abcqweracb
//输出abcqwer