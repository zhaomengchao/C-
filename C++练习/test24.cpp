//一个正整数可以分解一个或多个数组的积   例如32 = 2*2*3*3，返回2

#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,j,t;
    int a[100];
    while(scanf("%d",&n)!=EOF)
    {
        int j=0;
        t=0;
        for(i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                n/=i;
                t++;
            }
            while(n%i==0)
            {
                n/=i;
            }
        }
        if(n!=1)
          t++;
        printf("%d\n",t);
    }
    return 0;
}