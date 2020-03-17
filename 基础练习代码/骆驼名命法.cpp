/*骆驼命名法*/
/*输入hello_world
  输出helloWorld
  */

// write your code here cpp
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s1;
    while(cin >> s1)
    {
        string tmp;
        for(int i = 0; i < s1.size();i++)
        {
            if(s1[i] == '_')
            {
                tmp.push_back(s1[i+1]-32);
                ++i;
            }
            else
            {
                tmp.push_back(s1[i]);
            }
            
        }
        
        for(int i = 0; i < tmp.size();i++)
        {
            cout << tmp[i];
        }
        cout<<endl;
    }
    return 0;
}