/*������������������ A �� B������ A ��ĩ�����㹻�Ļ���ռ����� B�� ��дһ���������� B �ϲ��� A ������*/
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int pa = 0;
        int pb = 0;
        int sorted[m + n];
        int cur;

        
        while (pa < m || pb < n)
         {
            if (pa == m)
            {
                cur = B[pb++];
            }      
            else if (pb == n)
            {
                cur = A[pa++];
            }
                
            else if (A[pa] < B[pb])
            {
                cur = A[pa++];
            }  
            else
                cur = B[pb++];
            sorted[pa + pb - 1] = cur;
        }
        
        for(int i = 0; i != m +n;i++)
        {
            A[i] = sorted[i];
        }

    }
};