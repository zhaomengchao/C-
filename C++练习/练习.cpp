#include<iostream>
#include<string>
//����һ���ַ�����������ַ����������ַ�����
//ÿ����������һ���ַ������ַ�����󳤶�Ϊ100����ֻ������ĸ��������Ϊ�մ������ִ�Сд
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

//����abcqweracb
//���abcqwer