/*
和为 K 的最少斐波那契数字数目

给你数字 k ，请你返回和为 k 的斐波那契数字的最少数目，其中，每个斐波那契数字都可以被使用多次。

斐波那契数字定义为：

F1 = 1
F2 = 1
Fn = Fn-1 + Fn-2 ， 其中 n > 2 。
数据保证对于给定的 k ，一定能找到可行解。

示例 1：

输入：k = 7
输出：2 
解释：斐波那契数字为：1，1，2，3，5，8，13，……
对于 k = 7 ，我们可以得到 2 + 5 = 7 。
示例 2：

输入：k = 10
输出：2 
解释：对于 k = 10 ，我们可以得到 2 + 8 = 10 
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