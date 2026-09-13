class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> one, two;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(img1[i][j]) one.push_back({i, j});
                if(img2[i][j]) two.push_back({i, j});                
            }
        }
        int ans = 0;
        vector<vector<int>> check(2 * n, vector<int>(2 * n, 0));
        for(auto i : one) {
            for(auto j : two) {
                int horizontal = i.first - j.first + n;
                int vertical = i.second - j.second + n;
                ans = max(ans, ++check[horizontal][vertical]);
            }
        }
        return ans;
    }
};