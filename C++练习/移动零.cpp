//����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
/*
����: [0,1,0,3,12]
���: [1,3,12,0,0]
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int i,j;

        for(i = 0, j = 0; i < nums.size();i++)
        {
            if(nums[i] != 0)
            {
                swap(nums[i],nums[j]);
                j++;
            }
        }

    }
};