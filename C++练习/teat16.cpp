×Ö·û´®·´×ª
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s1;
    cin >> s1;
    for(int i = s1.size()-1; i >= 0;i--)
    {
         cout << s1[i];
     }
    
    return 0;
}