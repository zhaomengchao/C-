//输入：nums = [12,345,2,6,7896]
//输出：2
//解释：
//12 是 2 位数字（位数为偶数）?
//345 是 3 位数字（位数为奇数）??
//2 是 1 位数字（位数为奇数）?
//6 是 1 位数字 位数为奇数）?
//7896 是 4 位数字（位数为偶数）??
//因此只有 12 和 7896 是位数为偶数的数字


class Solution {
public:
    int judge(int n)
    {
        int count = 0;
        while(n)
            {
                count++;
                n = n / 10;
            }
            if(count % 2 == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
    }
    int findNumbers(vector<int>& nums) {
        
        int num = 0;
        for(int i = 0; i < nums.size();i++)
        {
            num += judge(nums[i]);
        }
        return num;
    }
};