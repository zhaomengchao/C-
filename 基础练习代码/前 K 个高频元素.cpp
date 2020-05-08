//给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>m;
        for(auto num : nums)    //  存到哈希结构里
            m[num]++;
        vector<pair<int,int >>v;
        vector<int>ans;
        for(auto it : m)        //  存到用于对value排序的容器里
            v.push_back(make_pair(it.first,it.second));
        sort(v.begin(),v.end(),[](pair<int,int> &a,pair<int,int> &b)->bool{return a.second>b.second;}  );
        //  对容器中的pair按照出现次数从大到小排序
       
        for(int i=0;k;++i,--k)
            ans.push_back(v[i].first);

        return ans;
    }
};

