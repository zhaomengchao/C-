﻿/*一个长度为n-1的递增排序数组中的所有数字都是唯一的，
并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中
有且只有一个数字不在该数组中，请找出这个数字。*/
/*输入: [0,1,3]
输出: 2
二分法
*/



class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }
        int len = nums.size();
        int left = 0;
        int right = len - 1;

        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] == mid)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
};