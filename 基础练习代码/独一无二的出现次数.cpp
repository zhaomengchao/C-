//����һ���������� arr�������æͳ��������ÿ�����ĳ��ִ�����

//���ÿ�����ĳ��ִ������Ƕ�һ�޶��ģ��ͷ��� true�����򷵻� false

//arr = [1,2,2,1,1,3]
//�����true
//���ͣ��ڸ������У�1 ������ 3 �Σ�2 ������ 2 �Σ�3 ֻ������ 1 �Ρ�û���������ĳ��ִ�����ͬ


class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        set<int> st;
        for (int i = 0; i < arr.size(); i++)
        {
             mp[arr[i]]++;
        }
        for (auto it = mp.begin();it != mp.end();it++)
        {
            st.insert((*it).second);
        }
        if (mp.size() == st.size())
            return true;
        return false;

    }
};