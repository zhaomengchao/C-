//构建乘积数组
/*输入[1 2 3 4 5]
  输出[120 60 40 30 24]
  */
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> b(n,1);

        int left = 1;
        for(int i = 0;i < n; i++)
        {
            b[i] = left;
            left = left * a[i];
        }
        int right = 1;
        for(int i = n - 1;i >= 0;i--)
        {
            b[i] *= right;
            right *= a[i];
        }        

        return b;
    }
};