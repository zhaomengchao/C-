//���磬���������Σ�

//[
//     [2],
//    [3,4],
//   [6,5,7],
//  [4,1,8,3]
//]
//�Զ����µ���С·����Ϊ?11������2?+?3?+?5?+?1?= 11����

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=triangle.size()-2; i>=0; i--) 
            for(int j=0; j<triangle[i].size(); j++) 
                triangle[i][j] = min(triangle[i+1][j],triangle[i+1][j+1]) + triangle[i][j];  
        return triangle[0][0];
    }
};
