/*
分糖果
给定一个偶数长度的数组，其中不同的数字代表着不同种类的糖果，每一个数字代表一个糖果。
你需要把这些糖果平均分给一个弟弟和一个妹妹。返回妹妹可以获得的最大糖果的种类数。

输入: candies = [1,1,2,3]
输出: 2
解析: 妹妹获得糖果[2,3],弟弟获得糖果[1,1]，妹妹有两种不同的糖果，弟弟只有一种。这样使得妹妹可以获得的糖果种类数最多

思路：进行set去重 计算出种类，然后与糖果数量进行比较 进行取小
https://leetcode-cn.com/problems/distribute-candies/
。
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