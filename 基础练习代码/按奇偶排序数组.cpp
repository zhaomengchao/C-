
//����һ���Ǹ��������� A��
//����һ�����飬�ڸ������У� A ������ż��Ԫ��֮�������������Ԫ�ء�
//���룺[3,1,2,4]
//�����[2,4,3,1]һ�����
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int left = 0;
        int right = A.size()-1;

        while(left < right)
        {
            if(A[left] % 2 != 0 && A[right] % 2 == 0)
            {
                int tmp = A[left];
                A[left] = A[right];
                A[right] = tmp;
            }
            if(A[left] % 2 == 0 )
            {
                left++;
            }
            if(A[right] % 2 != 0)
            {
                right--;
            }
        }
        return A;
    }

};