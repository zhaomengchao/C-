/*
���ǹ�
����һ��ż�����ȵ����飬���в�ͬ�����ִ����Ų�ͬ������ǹ���ÿһ�����ִ���һ���ǹ���
����Ҫ����Щ�ǹ�ƽ���ָ�һ���ܵܺ�һ�����á��������ÿ��Ի�õ�����ǹ�����������

����: candies = [1,1,2,3]
���: 2
����: ���û���ǹ�[2,3],�ܻܵ���ǹ�[1,1]�����������ֲ�ͬ���ǹ����ܵ�ֻ��һ�֡�����ʹ�����ÿ��Ի�õ��ǹ����������

˼·������setȥ�� ��������࣬Ȼ�����ǹ��������бȽ� ����ȡС
https://leetcode-cn.com/problems/distribute-candies/
��
*/
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> res;

        for(int i = 0; i < candies.size();i++)
        {
            res.insert(candies[i]);
        }

        return min(res.size(),candies.size()/2);
    }
};