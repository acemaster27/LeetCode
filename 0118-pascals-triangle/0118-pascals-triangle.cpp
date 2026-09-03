class Solution {
public:
    vector<vector<int>> generate(int n) {
        if(n == 1) return {{1}};
        vector<vector<int>> ans;
        ans.push_back({1});
        ans.push_back({1,1});
        n-= 2;
        while(n--) {
            vector<int> prev = ans.back();
            int m = prev.size();
            vector<int> next(m + 1);
            next[0] = 1, next[m] = 1;
            for(int i = 1; i < m; i++) {
                next[i] = prev[i - 1] + prev[i];
            }
            ans.push_back(next);
        }
        return ans;
    }
};