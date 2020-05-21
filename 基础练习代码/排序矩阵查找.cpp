/*给定M×N矩阵，每一行、每一列都按升序排列，请编写代码找出某元素。
找到返回true,找不到返回False*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.size() == 0 || matrix[0].size() == 0)
        {
            return false;
        }
        int row = matrix.size()-1;
        int col = 0;

        

        while(row >= 0 && row <= matrix.size()-1 && col >= 0 && col <= matrix[0].size()-1)
        {
            if(matrix[row][col] > target)
            {
                row--;
            }
            else if(matrix[row][col] < target)
            {
                col++;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};