//编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //构建两个数组分别存储行列
        int m = matrix.size();
        int n = matrix[0].size();

        vector<bool> row(m,false);
        vector<bool> col(n,false);

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        
        for(int i = 0; i < m;i++)
        {
            for(int j = 0; j < n;j++)
            {
                if(row[i] || col[j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};