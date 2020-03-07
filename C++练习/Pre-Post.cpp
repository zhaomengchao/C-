#include<iostream>
#include<string> 
using namespace std;  
int c[21][21],n;
long long solve(string pre,string post){  
    long long sum=1;  
    int num=0,k=0,i;  
    pre.erase(pre.begin());  
    post=post.substr(0, post.length()-1);  
    while (k<pre.length())
        for (i=0;i<post.length();i++)  
            if (pre[k]==post[i]){  
                sum*=solve(pre.substr(k,i-k+1),post.substr(k,i-k+1));  
                num++,k=i+1;break;  
            }  
    sum*=c[num][n];
    return sum;  
}  
void init(){  
    int i,j;  
    c[0][1]=c[1][1]=1;  
    for(i=2;i<21;i++)    
        for(c[0][i]=1,j=1;j<=i;j++) 
            if(i==j) c[j][i]=1;  
            else c[j][i]=c[j-1][i-1]+c[j][i-1];  
  
}  
int main(){  
    string pre,post;  
    init();  
    while(cin>>n>>pre>>post&&n)
        cout<<solve(pre,post)<<endl;
} 