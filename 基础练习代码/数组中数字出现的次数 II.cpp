/*��һ������ nums �г�һ������ֻ����һ��֮�⣬�������ֶ����������Ρ����ҳ��Ǹ�ֻ����һ�ε����֡�*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto e : nums)
        {
            m[e]++;
        }
        int result;

        for(auto p : m)
        {
            if(p.second == 1)
            {
                result = p.first;
                break;
            }
        }
        return result;
    }
};