class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        int i = 0, j = 0, d = 0, count = 1;
        vector<int> hor = {1, 0, -1, 0};
        vector<int> ver = {0, -1, 0, 1};
        vector<int> ans;
        ans.push_back(matrix[0][0]);
        matrix[0][0] = 101;
        while(true) {
            d %= 4;
            int x = i + ver[d], y = j + hor[d];
            if(x < row && y < col && x >= 0 && y >= 0 && matrix[x][y] != 101) {
                ans.push_back(matrix[x][y]);
                i += ver[d];
                j += hor[d];
                count++;
                matrix[x][y] = 101;
            } else {
                d++;
            }
            if(count == row * col) break;
        }
        return ans;
    }
};