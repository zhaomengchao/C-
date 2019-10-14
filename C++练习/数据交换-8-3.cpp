#include<iostream>  
using namespace std;  
void enter(int *m)  
{  
    for(int i=0;i<10;i++)  
    cin>>m[i];  
}  
void key(int *m)  
{  
    int max=m[0],min=m[0],n=0,k=0,z;  
    for(int i=1;i<10;i++)  
    {  
        if(max<m[i])  
        {  
            max=m[i];  
            n=i;  
        }  
    }  
    for(int i=1;i<10;i++)  
    {  
        if(min>m[i])  
        {  
            min=m[i];  
            k=i;  
        }  
    }  
    if(n==0&&k==9)  
    {  
        z=m[0];m[0]=m[9];m[9]=z;  
    }  
    else if(n==0&&k!=9)  
    {  
        z=m[9];m[9]=m[n];m[n]=z;  
        z=m[0];m[0]=m[k];m[k]=z;  
    }  
    else  
    {  
    z=m[0];m[0]=m[k];m[k]=z;  
    z=m[9];m[9]=m[n];m[n]=z;  
    }  
}  
void print(int *m)  
{  
    for(int i=0;i<10;i++)  
    cout<<m[i]<<' ';  
}  
int main()  
{  
    int ans[10];  
    enter(ans);  
    key(ans);  
    print(ans);  
    return 0;  
} 
