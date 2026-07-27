class Solution {
public:
    void Solve(int open, int close, int n, string &st, vector<string> &ans) {
        if(close == n) {
            ans.push_back(st);
        }
        if(open < n) {
            st += '(';
            Solve(open + 1, close, n, st, ans); 
            st.pop_back();
        }
        if(open > close) {
            st += ')';
            Solve(open, close + 1, n, st, ans);
            st.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string st = "";
        Solve(0, 0, n, st, ans);
        return ans;
    }
};