//一只青蛙一次可以跳上1个台阶，也可以一次跳2个台阶，
//青蛙跳上一个n级台阶，有多少种办法

class Solution {
public:
    int jumpFloorII(int number) {
        if(number == 1)
        {
            return 1;
        }
        if(number == 2)
        {
            return 2;
        }
        else
        {
            return jumpFloorII(number-1)*2;
        }
    }
};