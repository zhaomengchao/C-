/*在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。请完成一个函数，
输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。*/

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
        {
            return false;
        }
        int n = matrix.size(), m = matrix[0].size();
        int x = n - 1, y = 0;

        while(x >= 0 && y < n)
        {
            if (matrix[x][y] == target) return true;
            if (matrix[x][y] > target) x--;
            else y++;
        }
        return false;
    }
};