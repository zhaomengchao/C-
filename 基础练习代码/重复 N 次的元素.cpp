//�ڴ�СΪ 2N ������ A ���� N+1 ����ͬ��Ԫ�أ�������һ��Ԫ���ظ��� N �Ρ�
//�����ظ��� N �ε��Ǹ�Ԫ�ء�
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