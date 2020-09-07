/*
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
*/
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        
        int n = data.size();
        int tmp = 0;
        for(int i = 0; i < n;i++)
        {
            tmp ^= data[i];
        }
        
        int pos = 0; //记录第一个为一的位置
        
        while((tmp & 1) != 1)
        {
            pos++;
            tmp >>= 1;
        }
        
        *num1 = 0;
        *num2 = 0;
        
        for(int i = 0; i < n;i++)
        {
            if((data[i] >> pos)& 1 == 1)
            {
                *num1 ^= data[i];
            }
            else{
                *num2 ^= data[i];
            }
        }
    }
};