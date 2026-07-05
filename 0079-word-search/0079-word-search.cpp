class Solution {
public:
    vector<int> r = {1, -1, 0, 0};
    vector<int> c = {0, 0, 1, -1};
    bool Solve(vector<vector<char>> &board, string word, int row, int col, int index, vector<vector<bool>> &visited) {
        visited[row][col] = true;
        if(index == word.size()) return true;
        for(int i = 0; i < 4; i++) {
            int nr = row + r[i];
            int nc = col + c[i];
            if(nr >= 0 && nc >= 0 && nr < board.size() && nc < board[0].size() && board[nr][nc] == word[index] && !visited[nr][nc]) {
                if(Solve(board, word, nr, nc, index + 1, visited)) return true;
            }
        }
        visited[row][col] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0]) {
                    for (auto& row : visited) {
                        fill(row.begin(), row.end(), false);
                    }
                    if(Solve(board, word, i, j, 1, visited)) return true;
                }
            }
        }
        return false;
    }
};