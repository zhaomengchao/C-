/*
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
*/

class Solution {
public:
    int translateNum(int num) {
         if(num >= 0 && num < 10)
            return 1;
        int temp = num % 100;//取后两位数
        //如果不在10~25之间，则最后一位数只能单独翻译，翻译次数和前n-1位数一样
        if(temp < 10 || temp > 25)
            return translateNum(num/10);
        //否则，最后一位数可以单独翻译，也可以和前一位组合翻译
        else
        {
            return translateNum(num/10) + translateNum(num/100);
        }
    }
};