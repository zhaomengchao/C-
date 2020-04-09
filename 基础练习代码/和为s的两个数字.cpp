/*
����һ����������������һ������s���������в�����������ʹ�����ǵĺ�������s��
����ж�����ֵĺ͵���s�����������һ�Լ��ɡ�
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