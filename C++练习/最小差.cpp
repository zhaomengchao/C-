/*输入：{1, 3, 15, 11, 2}, {23, 127, 235, 19, 8}
输出： 3，即数值对(11, 8)*/
class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        long res = INT_MAX;
        for(int i = 0,j = 0; i < a.size()&&j < b.size();)
        {
            res = min(res,abs(long(a[i])- long(b[j])));
            if(a[i] > b[j])
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        return res;
        
    }
};