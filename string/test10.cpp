//求两个超长正整数相加
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s1;
    string s2;
    while( cin >> s1 >> s2)
    {
        string ret;
        int end1 = s1.size() - 1;
        int end2 = s2.size() - 1;
        int next = 0;//进位
        
        while(end1 >= 0 || end2 >=0)
        {
            long long add = 0;
            long long val1,val2;//存字符串中每字符
            
            if(end1 >= 0)
            {
                val1 = s1[end1] - '0';
                --end1;
            }
            else
            {
                val1 = 0;
            }
            if(end2 >= 0)
            {
                val2 = s2[end2] - '0';
                --end2;
            }
            else
            {
                val2 = 0;
            }
            
            add = val1 + val2 + next;
            
            if(add > 9)
            {
                add -= 10;
                next = 1;
            }
            else
            {
                next = 0;
            }
            ret.insert(ret.begin(),add + '0');
        }
        if(next == 1)
        {
            ret.insert(ret.begin(),'1');
        }
        cout << ret << endl;
    }
    return 0;
}