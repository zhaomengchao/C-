/*
��Ϊ K ������쳲�����������Ŀ

�������� k �����㷵�غ�Ϊ k ��쳲��������ֵ�������Ŀ�����У�ÿ��쳲��������ֶ����Ա�ʹ�ö�Ρ�

쳲��������ֶ���Ϊ��

F1 = 1
F2 = 1
Fn = Fn-1 + Fn-2 �� ���� n > 2 ��
���ݱ�֤���ڸ����� k ��һ�����ҵ����н⡣

ʾ�� 1��

���룺k = 7
�����2 
���ͣ�쳲���������Ϊ��1��1��2��3��5��8��13������
���� k = 7 �����ǿ��Եõ� 2 + 5 = 7 ��
ʾ�� 2��

���룺k = 10
�����2 
���ͣ����� k = 10 �����ǿ��Եõ� 2 + 8 = 10 
https://leetcode-cn.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/
*/
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int a = 1,b = 1;
        vector<int> fbi = {a,b};
        while(a+b<= k)
        {
            fbi.push_back(a+b);
            int f = a + b;
            a = b;
            b = f;
        }
        int count = 0;
        for(int i = fbi.size()-1; i >= 0; i--)
        {
            if(k >= fbi[i])
            {
                count++;

                k -= fbi[i];
            }
        }

        return count;


    }
};