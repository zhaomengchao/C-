//第三大数
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> hash_set;
        
        for(auto n:nums){
            hash_set.insert(n);
            if(hash_set.size()>3)
                hash_set.erase(*(hash_set.begin()));
        }
        if(hash_set.size()<3)
            return *(hash_set.rbegin());
        else
            return *(hash_set.begin());
    }
};
