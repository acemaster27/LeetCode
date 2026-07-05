class Solution {
public:
    vector<int> col;
    vector<int> row;
    vector<int> posDiag;
    vector<int> negDiag;
    vector<vector<string>> ans;

    bool isSafe(int r, int c, int n) {
        if(row[r] || col[c] || posDiag[r + c] || negDiag[r - c + n - 1]) return false;
        return true;
    }

    void Solve(int r, int n, vector<string> &board) {
        if(r == n) {
            ans.push_back(board);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(isSafe(r, i, n)) {
                board[r][i] = 'Q';
                row[r] = 1;
                col[i] = 1;
                posDiag[r + i] = 1;
                negDiag[r - i + n - 1] = 1;
                Solve(r + 1, n, board);
                board[r][i] = '.';
                row[r] = 0;
                col[i] = 0;
                posDiag[r + i] = 0;
                negDiag[r - i + n - 1] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        col.resize(n, 0);
        row.resize(n, 0);
        posDiag.resize(2 * n - 1, 0);
        negDiag.resize(2 * n - 1, 0);
        Solve(0, n, board);
        return ans;
    }
};
    

