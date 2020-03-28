/*礼物的最大价值*/
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        dp[0][0] = grid[0][0];
        for(size_t i=1; i<grid.size(); ++i) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(size_t j=1; j<grid[0].size(); ++j) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }

        for(size_t i=1; i<grid.size(); ++i) {
            for(size_t j=1; j<grid[0].size(); ++j) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
    
};

