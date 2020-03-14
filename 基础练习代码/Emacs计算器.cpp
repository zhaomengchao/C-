// write your code here cpp
//将数字存入栈中，当出现操作数时，进行出栈，进行运算
#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
    int n;
    while(cin >> n)
    {
        string s;
        stack<int> st;
        
        for(int i = 0; i < n;i++)
        {
            cin >> s;
            if(s.size() == 1 && (s[0] == '+' || s[0] == '-' ||s[0] == '*' || s[0] == '/'))
            {
                int r = st.top();//右操作数
                st.pop();
                int l = st.top();
                st.pop();
                
                switch(s[0])
                {
                        case'+':
                            st.push(l+r);
                            break;
                        case'-':
                            st.push(l-r);
                            break;
                        case'*':
                            st.push(l*r);
                            break;
                        case'/':
                            st.push(l/r);
                            break;
                }
            }
            else{//遇见数字进栈
                int a = stoi(s);
                st.push(a);
            }
        }
        cout << st.top() <<endl;
    }
    return 0;
}