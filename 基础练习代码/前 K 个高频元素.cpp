//����һ���ǿյ��������飬�������г���Ƶ��ǰ k �ߵ�Ԫ�ء�
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>m;
        for(auto num : nums)    //  �浽��ϣ�ṹ��
            m[num]++;
        vector<pair<int,int >>v;
        vector<int>ans;
        for(auto it : m)        //  �浽���ڶ�value�����������
            v.push_back(make_pair(it.first,it.second));
        sort(v.begin(),v.end(),[](pair<int,int> &a,pair<int,int> &b)->bool{return a.second>b.second;}  );
        //  �������е�pair���ճ��ִ����Ӵ�С����
       
        for(int i=0;k;++i,--k)
            ans.push_back(v[i].first);

        return ans;
    }
};

