/*
和谐数组是指一个数组里元素的最大值和最小值之间的差别正好是1。

现在，给定一个整数数组，你需要在所有可能的子序列中找到最长的和谐子序列的长度。
https://leetcode-cn.com/problems/longest-harmonious-subsequence/
*/
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int>m;
		int maxx = 0;
		for (int i : nums) {
			m[i]++;
		}
		for (auto i : m) {
			if (m.count(i.first + 1))
				maxx = max(maxx, i.second + m[i.first + 1]);
		}
		return maxx;
    }
};