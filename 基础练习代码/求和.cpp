//��ͣ�������������n,m��������������ȡ��������ʹ��͵���m
#include <iostream>
#include <vector>
using namespace std;
 
//�������һ�����͵ı�������
//ͨ����������Ϊ���������ѡ�񡢲�ѡ��
//���ѡ��ǰֵ����ô�����ռ��val����Ҫ�ӵ�����
//�����ѡ����ô����������һ�ε�
//
//�ݹ��˳�������m = 0����ʾ��ǰ��������ǡ�þ��ǽ������Ҫ��ӡ
//m<0����ʾ��ǰ�����Ѿ����㣬���Ա����������ֲ�������Ҫ��
//start > n��ʾһ�ֱ������
void GetFunc(int start,int n,int m,vector<int> v)
{
    //n:��1��n������
    //m:��ʾ�����ռ�
    if(m == 0)
    {
        for(int i =0;i<v.size();++i)
            i == 0 ? cout<<v[i]:cout<<" "<<v[i];
        cout<<endl;
        return;
    }
 
    if(m < 0 || start>n)
        return;
 
    //Ҫ
    v.push_back(start);
    GetFunc(start+1,n,m-start,v);
 
    //��Ҫ
    v.pop_back();
    GetFunc(start+1,n,m,v);
}
 
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        vector<int> v;
        int start = 1;
        GetFunc(start,n,m,v);
    }
    return 0;
}