//�ַ�����������������ִ�
//abcd123sdf123456
//123456
#include<iostream>
#include<string>

using namespace std;
int main()
{
    string str;//�洢�����ַ���
    string str1;//��ʱ�洢����
    string maxnum;//��洢
    getline(cin,str);
    int size = str.size();
    
    for(int i = 0; i <= size; i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            str1 += str[i];//�洢�����ַ�
        }
        //����������ʱ���жϵ�ǰ�Ƿ�Ϊ�
        else
        {
            if(str1.size() > maxnum.size())
            {
                maxnum = str1;//����ǣ��Ͱ�����maxnum;
            }
            else
                str1.clear();//�������str1
        }
    }
    cout << maxnum <<endl;
    return 0;
}