/*����һ������Ϊn���������飬���Խ��仮��Ϊ�������֣�����[0 - k] [k +1, N-1]
���󲿷��������ȥ�Ҳ������ֵ
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