class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        // 位运算。将数组分为两个部分。每一部分只含有一个出现一次的数字，其余部分为重复数字。
        // 对数组进行一遍异或运算。根据结果中出现1的位置，可以将数组分为两部分
        int len = nums.size();
        vector<int> res(2,0);
      
        
        int temp = 0; // 用于对nums数组进行一遍异或运算
        for(int i=0;i<len;i++){
            temp = temp^nums[i];
        }
        // 寻找temp二进制第一个为1的位置
        int pos = 0; //记录要右移的位数
        while((temp&1)!=1){
            pos++;
            temp = temp>>1;
        }
        // cout<<pos<<endl;
        //根据该pos位置将nums分为两部分，直接进行位运算
        for(int i=0;i<len;i++){
            if((nums[i]>>pos)&1==1){
                res[0] = res[0]^nums[i];
            }
            else res[1] = res[1]^nums[i];
        }
        return res;
    }
};