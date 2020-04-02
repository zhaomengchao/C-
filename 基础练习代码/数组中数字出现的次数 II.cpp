/*在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。*/
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