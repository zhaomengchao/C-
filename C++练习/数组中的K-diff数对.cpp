/*
给定一个整数数组和一个整数?k, 你需要在数组里找到不同的?k-diff 数对。
这里将?k-diff?数对定义为一个整数对 (i, j), 其中 i 和 j 都是数组中的数字，且两数之差的绝对值是?k.

输入: [3, 1, 4, 1, 5], k = 2
输出: 2
解释: 数组中有两个 2-diff 数对, (1, 3) 和 (3, 5)。
尽管数组中有两个1，但我们只应返回不同的数对的数量。
*/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int count = 0;

        if(k < 0)//好坑不止有-1?还有-157
            return 0;

        if(k == 0) {
        //当k=0时，其实就是找数组中有没有重复元素?且重复元素个数大于等于2时?我们都视为只有1组K-diff
            for(int i = 0; i < nums.size(); i++) {
            ++map[nums[i]];
            if(map[nums[i]] == 2)
                count++;
            }
            return count;
        }
        //k为其他数字时，先构建hash表，将value初始化为0.
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]] = 0;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(map.find(nums[i] - k) != map.end()) {
            //若nums[i]-k存在于数组中。注：nums[i]-k必然小于nums[i]?diff数对为{num[i],?nums[i]-k}
                if(map[nums[i]] == 0 ) {//已经存在的diff数对中还没有出现过nums[i]为第一个数
                    count++;//数对数量+1
                    map[nums[i]] = 1;//给nums[i]标记，表示已经有nums[i]开头的数对了，后面不再考虑
                }
            }
        }
        return count;
    }
};

