/*
找第k小的数，相同的数为一个数
142322568
第三小的数是 3

*/

#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        int *a=new int[n],k,pos=1;
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        cin>>k;
        if(k==1)
            cout<<a[0];
        else{
            for(int i=1;i<n;i++){
                if(a[i]!=a[i-1])
                    pos++;
                if(pos==k){
                    cout<<a[i]<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}