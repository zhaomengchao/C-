/*һֻ����һ�ο�������1��̨�ף�Ҳ��������2��̨�ס������������һ�� n?����̨���ܹ��ж�����������

����Ҫȡģ 1e9+7��1000000007����������ʼ���Ϊ��1000000008���뷵�� 1��*/
//���ε�쳲�������

class Solution {
public:
    int numWays(int n) {
        if(n == 0)
            return 1;
        if(n == 1)
        {
            return 1;
        }
        if( n == 2)
        {
            return 2;
        }
        int fib = 0;
        int fib1 = 1;
        int fib2 = 2;

        for(int i = 3;i <= n;i++)
        {
            fib = (fib1+fib2)%1000000007;
            fib1 = fib2;
            fib2 = fib;
        }
        return fib;
    }
};

