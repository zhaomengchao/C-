//ƹ�����
//A�е��ַ���������B�е��ַ���������B�еĴ���С��A,���Yes

// write your code here cpp
#include<iostream>
#include<string>

using namespace std;

string help(string s1,string s2)
{
    int j = 0;
    for(int i  = 0; i < s2.size();i++)
    {
        int pos = s1.find(s2[i], j);
        if(pos < s1.size())
        {
            s1.erase(pos,1);
        }
        else
            return "No";
    }
    return "Yes";
}
int main()
{
    string s1,s2;
    while(cin >> s1 >> s2)
    {
        cout << help(s1,s2) << endl;
    }
    return 0;
}