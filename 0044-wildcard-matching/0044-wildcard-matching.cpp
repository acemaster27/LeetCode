class Solution {
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        if(i < 0 && j < 0) {
            return true;
        }
        if(i >= 0 && j < 0) {
            return false;
        }
        if(i < 0 && j >= 0) {
            return check(p, j);
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);
        } 

        if(p[j] == '*') {
            return dp[i][j] = solve(i - 1, j, s, p, dp) || solve(i, j - 1, s, p, dp);
        }

        return dp[i][j] = false;
    }
    bool check(string &p, int j) {
        for(int i = 0; i <= j; i++) {
            if(p[i] != '*') return false;
        }
        return true;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length(), vector<int>(p.length(), -1));
        return solve(s.length() - 1, p.length() - 1, s, p, dp);
    }
};