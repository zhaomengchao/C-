/*
给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2,2]
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    
        vector<int> res;
        unordered_map<int,int> ts;

        for(int i:nums1)
            ts[i]++;   

         for(int i:nums2)       
            if(ts.find(i)!=ts.end() && --ts[i] >= 0)        //如果map中此时key为i对应的value大于等于1,即交集元素
            res.push_back(i);  

       return res;
    }
};