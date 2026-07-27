class Solution {
public:
    void Solve(int open, int close, int n, string st, vector<string> &ans) {
        if(close == n) {
            ans.push_back(st);
        }
        if(open < n) {
            Solve(open + 1, close, n, st + '(', ans); 
        }
        if(open > close) {
            Solve(open, close + 1, n, st + ')', ans);
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string st = "";
        Solve(0, 0, n, st, ans);
        return ans;
    }
};