/*
674. �������������
����һ��δ��������������飬�ҵ���������ĵĵ������У������ظ����еĳ��ȡ�

 

ʾ�� 1:

����: [1,3,5,4,7]
���: 3
����: ��������������� [1,3,5], ����Ϊ3��
���� [1,3,5,7] Ҳ�������������, �������������ģ���Ϊ5��7��ԭ�����ﱻ4������ 
https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/
*/
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()==0)  return 0;
        int res=1;
        int temp=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
                temp++;
            else if(nums[i]<=nums[i-1])
                temp=1;
            res=max(res,temp);
        }
        return res;
    }
};