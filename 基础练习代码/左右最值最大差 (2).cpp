/*
����һ������ΪN(N>1)����������A�����Խ�A���ֳ������������֣��󲿷�A[0..K]���Ҳ���A[K+1..N-1]��
K����ȡֵ�ķ�Χ��[0,N-2]������ô�໮�ַ����У��󲿷��е����ֵ��ȥ�Ҳ������ֵ�ľ���ֵ������Ƕ��٣�
������������A������Ĵ�Сn���뷵����Ŀ����Ĵ�
*/
class MaxGap {
public:
    int findMaxGap(vector<int> A, int n) {
        // write code here
        int max = A[0];
        for(int i = 1; i < n;i++)
        {
            if(max < A[i])
            {
                max = A[i];
            }
        }
        int minnum = min(A[0],A[n - 1]);
        return max - minnum;
    }
};