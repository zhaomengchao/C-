/*一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n?级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。*/
//变形的斐波那契数

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

