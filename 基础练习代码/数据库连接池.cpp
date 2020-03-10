//数据库连接池
/*
输入
6
A connect
A disconnect
B connect
C connect
B disconnect
C disconnect
输出
2
*/
/*思路：求解最大连接数，每次如果显示连接，将他入栈，如果显示不连接，先比较count与栈的大小，记录最大的数，然后出栈，继续向下比较*/

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