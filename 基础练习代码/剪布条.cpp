//s1中有多少个s2
//剪布条
/*
输入abcde a3
	aaaaaa aa
输出0
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
        if(pos != -1)//表示找到
        {
            count++;
            i = pos + t.size();//从找到位置每次向后移动t.size()个位置，继续查找
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