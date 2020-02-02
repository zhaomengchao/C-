//搜索插入位置
//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
//如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        for(int i = 0; i < size; i++)
        {
            if(nums[i] >= target)
            {
                return i;
            }
        }
        return size;
    }
};