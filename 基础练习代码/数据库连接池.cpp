//���ݿ����ӳ�
/*
����
6
A connect
A disconnect
B connect
C connect
B disconnect
C disconnect
���
2
*/
/*˼·����������������ÿ�������ʾ���ӣ�������ջ�������ʾ�����ӣ��ȱȽ�count��ջ�Ĵ�С����¼��������Ȼ���ջ���������±Ƚ�*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int count = 0;
        stack<char> q;
        for(int i = 0; i < n; i++)
        {
            char c;
            cin >> c;
            string op;
            cin >> op;
            
            if(op == "connect")
            {
                q.push(c);
            }
            else
            {
                count = q.size() > count ? q.size():count;
                q.pop();
            }
            
        }
        cout << count << endl;
    }
    return 0;
}