/*�����б�*/
/*��һ�У�����֮���ö��Ÿ�������������а����ո���߶��ã���˫���Ű�������
�ڶ�������һ���������Ǵ������û���������
�����һ�г��ֵڶ����˵��������������Ignore
�������Important!
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
            string ret;//�洢����������
            if(s1[i] == '"')//�ҳ�˫�����ڵ�����
            {
                i++;
                while(i < s1.size() && s1[i] != '"')//���뵽ret�н��б���
                {
                    ret += s1[i];
                    i++;
                }
                if(ret == s2)//��s2���бȽ�
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