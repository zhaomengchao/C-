//���������ַ�������Ĺ����Ӵ�
��Ŀ����
���������ַ���a,b�е�������Ӵ������ж��,����ڽ϶̴���
���ȳ��ֵ��Ǹ���
��������:
���������ַ���
�������:
�����ظ����ֵ��ַ�
ʾ��1�������ʾ����������,��̨�������ݰ㲻����ʾ��
����
 abcdefghijklmnop
 abcsafjklmnopgrstuvw
���
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
        if(s1.size() > s2.size())//����������Ӵ�
        {
            swap(s1,s2);
        }
        string str;//�洢�ִ�
        string tmp;
        for(int i = 0; i < s1.size(); i++)
        {
            for(int j = i;j < s1.size();j++)
            {
                tmp = s1.substr(i,j-i+1);//string substr (size_t pos = 0, size_t len = npos) const;�ӵ�һ��Ԫ�ؿ�ʼ��len�����ȵ��Ӵ�
                if(int (s2.find(tmp)) < 0)//Ȼ����s2������Ӧ���Ӵ�
                {
                    break;
                }
                else if(str.size() < tmp.size())//��ÿһ���ҵ����Ӵ���ǰһ���ҵ����ִ�ȥ�Ƚϳ��ȣ���Ľ���С�Ĳ���
                {
                    str = tmp;
                }
            }
        }
        cout << str << endl��
    }
    return 0;
}