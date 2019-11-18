//求最大连续bit数
//功能: 求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1

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


