//s1���ж��ٸ�s2
//������
/*
����abcde a3
	aaaaaa aa
���0
	3
*/

// write your code here cpp
#include<iostream>
#include<string>

using namespace std;
int numbers(string s, string t)
{
    int count = 0;
    int i = 0;
    while(i < s.size())
    {
        int pos = 0;
        pos = s.find(t,i);
        if(pos != -1)//��ʾ�ҵ�
        {
            count++;
            i = pos + t.size();//���ҵ�λ��ÿ������ƶ�t.size()��λ�ã���������
        }
        else
        {
            break;
        }
    }
    return count;
}

int main()
{
    string s1,s2;
    while(cin >> s1 >> s2)
    {
        int n = numbers(s1,s2);
        cout << n << endl;
    }
    return 0;
}