
//求数组中出现次数最多的元素，并返回那元素的值

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int ret = nums.size()/2;
        
        return nums[ret];
    }
};