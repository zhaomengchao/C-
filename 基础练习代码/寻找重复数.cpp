//����һ������?n + 1 ������������?nums�������ֶ��� 1 �� n?֮�䣨���� 1 �� n����
//��֪���ٴ���һ���ظ�������������ֻ��һ���ظ����������ҳ�����ظ�������

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i)
            if (nums[i] == nums[i - 1]) return nums[i];
        return -1;

    }
};