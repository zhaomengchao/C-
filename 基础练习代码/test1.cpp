//���ǰѷ����������Ե�����?A?����ɽ����

//A.length >= 3
//���� 0 < i?< A.length - 1 
//ʹ��A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
//����һ��ȷ��Ϊɽ�������飬
//�����κ�����?A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]?�� i?��ֵ��

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int i = 0;
        while (A[i] < A[i+1]) i++;
        return i;

    }
};