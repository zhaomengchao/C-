/*��һ�� n * m �Ķ�ά�����У�ÿһ�ж����մ����ҵ�����˳������
ÿһ�ж����մ��ϵ��µ�����˳�����������һ��������
����������һ����ά�����һ���������ж��������Ƿ��и�������*/

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