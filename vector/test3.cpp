�������� 

1.�����ָ���Ϊ�ո� 
2.�����á������������Ĳ���������м��пո񣬲��ܽ���Ϊ�������������������������xcopy /s ��C:\program files�� ��d:\��ʱ��������Ȼ��4������3������Ӧ�����ַ���C:\program files��������C:\program��ע���������ʱ����Ҫ������ȥ�������Ų�����Ƕ�������
3.���������� 
4.������������֤��������ֲ�����Ҫ�����

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
        s2 = v[i];//��ȡ�ַ���,�������һ���ַ��������
        if(s2[0] == '"')
        {
            int a = s2.size();
            for(int j = 1; j < a-1;j++)
            {
                s3[j] = s2[j];//���ʱҪ������ȥ�������Լ�ȥ��
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