#include<iostream>
#include<vector>

using namespace std;



////删除排序数组中的重复项，双指针法
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int index = 0;
		if (nums.empty())
		{
			return 0;
		}

		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[index] != nums[i])
			{
				nums[++index] = nums[i];//注意一定是前置++
			}
		}
		return index + 1;
	}
};

