//一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
//请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int sign = 0;
        for(int n : nums) sign ^= n;
        //sign和-sign与运算之后，会产生倒数第二位二进制数为1，其他为0
        sign &= -sign;
        int n1 = 0, n2 = 0;
        //根据sign分组
        for(int n : nums){
            if(n & sign) n1 ^= n;
            else n2 ^= n;
        }
        return {n1, n2};
    }
};
