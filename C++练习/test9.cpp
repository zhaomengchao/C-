//���������bit��
//����: ��һ��byte���ֶ�Ӧ�Ķ�����������1�����������������3�Ķ�����Ϊ00000011���������2��1

#include<iostream>

using namespace std;

int main()
{
    int a = 0;
    while(cin >> a)
    {
        int max = 0;
        int count = 0;
        while(a)
        {
            if(a & 1)
            {
                count++;
                if(count > max)
                {
                    max = count;
                }
               
            }
             else
             {
                 count = 0;
             }
            a >>= 1;
        }
        cout << max << endl;
    }
   return 0;
}


