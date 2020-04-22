//统计前k个高频单词
class Solution {
public:
    static bool cmp(const pair<string,int>& a,const pair<string,int>& b){
        if(a.second==b.second)
            return a.first<b.first;
        return a.second>b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> m;
        vector<pair<string,int>> vec;
        vector<string> res;
        for(auto& e:words){
            m[e]++;
        }
        for(map<string,int>::iterator it=m.begin();it!=m.end();it++)
            vec.push_back(pair<string,int>(it->first,it->second));
        sort(vec.begin(),vec.end(),cmp);
        if(k<vec.size())
            vec.erase(vec.begin()+k,vec.end());
        for(auto& e:vec)
            res.push_back(e.first);
        for(auto& e:vec)
            cout<<e.first<<" "<<e.second<<endl;
        return res;
    }
};
