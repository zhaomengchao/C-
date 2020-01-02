//输入: nums1 = [1,2,2,1], nums2 = [2,2]
//输出: [2]


//输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//输出: [9,4]


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>perseve;
        for(auto v:nums1)    //遍历 v容器
        {
		//在nums2中查找有无相同
            vector<int>::iterator it = find(nums2.begin(),nums2.end(),v); 
			//没查到就返回迭代器 nums2.end（），查到就返回指向v元素的迭代器
            if(it!=nums2.end())        
            perseve.insert(*it);
        }
        vector<int>arr(perseve.begin(),perseve.end());    //用迭代器范围初始化vector容器
        return arr;
    }
};