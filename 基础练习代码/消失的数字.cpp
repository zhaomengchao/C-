/*数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
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
