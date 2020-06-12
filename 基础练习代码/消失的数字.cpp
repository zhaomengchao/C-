/*����nums������0��n������������������ȱ��һ�������д�����ҳ��Ǹ�ȱʧ�����������а취��O(n)ʱ���������
https://leetcode-cn.com/problems/missing-number-lcci/
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> memo(nums.size()+1, -1);
        for(int i = 0; i < nums.size(); i++)
            memo[nums[i]]=0;
        
        for(int i = 0; i < memo.size(); i++)
            if(memo[i]==-1) return i;
        return 0;
    }
};
