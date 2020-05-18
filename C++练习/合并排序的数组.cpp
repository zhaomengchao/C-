/*给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。*/
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