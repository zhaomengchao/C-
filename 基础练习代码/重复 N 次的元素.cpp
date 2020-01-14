//在大小为 2N 的数组 A 中有 N+1 个不同的元素，其中有一个元素重复了 N 次。
//返回重复了 N 次的那个元素。
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        sort(A.begin(),A.end());
        for(int i = 0; i < A.size();i++)
        {
            if(A[i] == A[i+1])
            {
                return A[i];
            }
        }
        return 0;
    }
};