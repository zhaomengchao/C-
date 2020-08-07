/*
给定一个不含空格的字符串，要求对该字符串逆序输出

*/
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char a[1000],b[1000];
	cin>>a;
	int len=strlen(a);
	int i;
	for( i=0;i<len;i++)
	{
		b[i]=a[len-i-1];
	}
	b[i] = '\0';
	cout<<b;
	return 0;
}
