//��һֻ����,�ӳ������3������ÿ���¶���һֻ����,С���ӳ�
���������º�ÿ��������һֻ����,�������Ӷ�����,��ÿ���µ�
��������Ϊ����?
���
ͳ�Ƴ�����������
@param monthCount�ڼ�����
@return��������
*
 public static int getTotalCount(int monthCount)
 return;

//�൱��쳲���������
//f(n) = f(n-1) + f(n - 2)
//n Ҫ������
//0 1 1 2 3 5 8 13 21 34
#include<iostream>
using namespace std;

int count(int n)
{
    int sum = 0;
    if(n == 1)
    {
        sum = 1;
    }
    else if(n == 2)
    {
        sum = 1;
    }
    else if(n == 3)
    {
        sum = 2;
    }
    else
    {
        sum += count(n - 1) + count(n - 2);
    }
    return sum;
}

int main()
{
    int n;
    while(cin >> n)
    {
        cout << count(n) << endl;
    }
    return 0;
}