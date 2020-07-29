/*
高度检查器
https://leetcode-cn.com/problems/height-checker/
思路：
我们只需对给定数组进行非递减排序，然后比较同一位置的数字是否相同 
不同则num ++ 即此时我们所统计出的num就是 将 原数组 排序成 非递减数列 的最小移动次数。

*/
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> tmp = heights;//数组赋值
        sort(heights.begin(),heights.end());
        int num = 0;
        for(int i = 0;i < heights.size();i++)
        {
            if(tmp[i] != heights[i])
                num++;
        }
        return num;
    }
};