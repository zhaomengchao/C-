// write your code here cpp
//�����ִ���ջ�У������ֲ�����ʱ�����г�ջ����������
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
                int r = st.top();//�Ҳ�����
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
            else{//�������ֽ�ջ
                int a = stoi(s);
                st.push(a);
            }
        }
        cout << st.top() <<endl;
    }
    return 0;
}