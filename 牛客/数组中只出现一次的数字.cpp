/*
һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�
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
        
        int pos = 0; //��¼��һ��Ϊһ��λ��
        
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