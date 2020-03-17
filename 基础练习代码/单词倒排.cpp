/*µ•¥ µπ≈≈*/
/* i am a student
student a am i*/
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str;
    getline(cin,str);
    int pos1=0;
    int pos2=int(str.length()-1);
    for(int i=int(str.length()-1);i>=0;--i)
    {
        if(str[i]==' ')
        {
            pos1=i;
            for(int j=pos1+1;j<=pos2;++j)
            {
                cout<<str[j];
            }
            cout<<str[pos1];
            while(str[--pos1]==' ') ;
            pos2=pos1;
            i=pos1++;
        }
        if(i==0)
        {
            for(int j=i;j<=pos2;++j)
            {
                cout<<str[j];
            }
        }
    }
    return 0;
}
