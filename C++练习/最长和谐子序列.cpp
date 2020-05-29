/*
��г������ָһ��������Ԫ�ص����ֵ����Сֵ֮��Ĳ��������1��

���ڣ�����һ���������飬����Ҫ�����п��ܵ����������ҵ���ĺ�г�����еĳ��ȡ�
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