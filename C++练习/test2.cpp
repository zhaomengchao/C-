#include<iostream>
#include<vector>

using namespace std;



////ɾ�����������е��ظ��˫ָ�뷨
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
				nums[++index] = nums[i];//ע��һ����ǰ��++
			}
		}
		return index + 1;
	}
};

