class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int num = 1;
        int i = 0, j = 0, d = 0;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        vector<int> hor = {1, 0, -1, 0};
        vector<int> ver = {0, -1, 0, 1};
        ans[0][0] = 1;
        while(true) {
            d %= 4;
            int x = i + ver[d], y = j + hor[d];
            if(x < n && y < n && x >= 0 && y >= 0 && ans[x][y] == 0) {
                ans[x][y] = ++num;
                i += ver[d];
                j += hor[d];
            } else {
                d++;
            }
            if(num == n * n) break;
        }
        return ans;
    }
};