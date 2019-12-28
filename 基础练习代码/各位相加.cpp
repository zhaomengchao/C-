//输入: 38
//输出: 2 
//解释: 各位相加的过程为：3 + 8 = 11, 1 + 1 = 2。 由于?2 是一位数，所以返回 2。
//进阶:
//不使用循环或者递归，且在 O(1) 时间复杂度内解决这个问题



class Solution {
public:
    int addDigits(int num) {
       if(num>9)
        {
            num=num%9;
            if(num==0)
                return 9;
        }
        return num;
    }
};