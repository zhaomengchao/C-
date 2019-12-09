#include<iostream>    
using namespace std;    
int main()    
{    
  long long  b=1,n,i,m,a;
  while(cin>>n&&n!=0&&n<=20&&n>=0)
  {
      for(i=0,b=1;i<n;i++)
      {
          b=b*5;
          a=b-4;
      }
          
      for(m=0;m<n;m++)
          a=a/5*4;
      a=a+n;
      cout<<b-4<<" "<<a<<endl;
  }
  return 0;    
}