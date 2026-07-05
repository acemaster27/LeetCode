class Solution {
public:
    vector<int> r = {1, -1, 0, 0};
    vector<int> c = {0, 0, 1, -1};
    bool Solve(vector<vector<char>> &board, string &word, int row, int col, int index) {
        char ch = board[row][col];
        board[row][col] = '.';
        if(index == word.size()) return true;
        for(int i = 0; i < 4; i++) {
            int nr = row + r[i];
            int nc = col + c[i];
            if(nr >= 0 && nc >= 0 && nr < board.size() && nc < board[0].size() && board[nr][nc] == word[index]) {
                if(Solve(board, word, nr, nc, index + 1)) return true;
            }
        }
        board[row][col] = ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0]) {
                    if(Solve(board, word, i, j, 1)) return true;
                }
            }
        }
        return false;
    }
};