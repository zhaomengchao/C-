
//�������г��ִ�������Ԫ�أ���������Ԫ�ص�ֵ

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int ret = nums.size()/2;
        
        return nums[ret];
    }
};