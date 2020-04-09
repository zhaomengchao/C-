/*
输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。
如果有多对数字的和等于s，则输出任意一对即可。
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int left = 0;
        int right = nums.size() - 1;
        while(left < right)
        {
            int sum = 0;
            sum = nums[left] + nums[right];
            if(sum == target)
            {
                res.push_back(nums[left]);
                res.push_back(nums[right]);
                break;
            }
            else if(sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        
        }
        return res;
    }
};