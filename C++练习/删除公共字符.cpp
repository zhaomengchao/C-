//删除公共字符

//举例：   输入： s1:They are students
	           s2:aeiou
//	输出： Thy r stdnts

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    for(int i = 0; i < s2.size();++i)
    {
        int index;
        while((index = s1.find(s2[i])) != -1)
        {
            s1.erase(index,1);
        }
    }
    cout<<s1<<endl;
    return 0;
}