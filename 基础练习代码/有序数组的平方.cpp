//给定一个按非递减顺序排序的整数数组 A，
//返回每个数字的平方组成的新数组，要求也按非递减顺序排序。
//示例 1：

//输入：[-4,-1,0,3,10]
//输出：[0,1,9,16,100]

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> tmp;
        for(int i = 0; i < A.size();i++)
        {
            tmp.push_back(A[i]*A[i]);
        }
        sort(tmp.begin(),tmp.end());
        return tmp;
    }
};