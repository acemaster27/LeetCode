class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[m - 1][n - 1] || obstacleGrid[0][0]) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(obstacleGrid[i][j]) {
                    dp[i][j] = -1;
                    continue;
                }
                else {
                    if(i > 0) dp[i][j] += max(dp[i - 1][j], 0);
                    if(j > 0) dp[i][j] += max(dp[i][j - 1], 0);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};