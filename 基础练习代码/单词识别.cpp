//A blockhouse is a small castle that has four openings through which to shoot.
输出

//a:2
//blockhouse:1 castle:1 four:1 has:1 is:1 openings:1 shoot:1 small:1 that:1 through:1 to:1 which:1
#include <iostream>
#include <map>
 
using namespace std;
 
int main()
{
    map<string,int>dict;
    string str;
    while(cin>>str)
    {
        for(int i = 0;i < str.size();i++)
        {
            if(str[i] >= 'A' && str[i] <= 'Z')
                str[i] += 32;
            if(str[i] == ',')
                str.erase(i,1);
            if(str[i] == '.')
                str.erase(i,1);
        }
        dict[str]++;//统计相同单词出现的次数
    }
    for(auto e: dict)
    {
        cout<<e.first<<":"<<e.second<<endl;
    }
    return 0;
}
