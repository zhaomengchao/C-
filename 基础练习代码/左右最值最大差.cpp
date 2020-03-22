/*给封一个长度为n的整型数组，可以将其划分为两个部分，划分[0 - k] [k +1, N-1]
求左部分最大数减去右部分最大值
*/
class MaxGap {
public:
    int findMaxGap(vector<int> A, int n) {
        // write code here
        int m = -1;
        for(int i =0; i < n;i++)
        {
            if(m < A[i])
            {
                m = A[i];
            }
        }
        return max((m-A[0]),(m - A[n-1]));
    }
};