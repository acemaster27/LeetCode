class Solution {
public:
    int Solve(vector<int>& dp, int n) {
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = Solve(dp, n - 1) + Solve(dp, n - 2);
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return Solve(dp, n);
    }
};