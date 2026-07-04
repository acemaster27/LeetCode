class Solution {
public:
    vector<int> parent;
    int find(int a) {
        if(parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) {
            if(a < b)
            parent[b] = a;
            else
            parent[a] = b;
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        parent.resize(n + 1, 0);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        for(auto road : roads) {
            int current = road[0];
            int next = road[1];
            unite(current, next);
        }

        int ans = 1e5;
        for(auto road : roads) {
            if(find(road[0]) == parent[1])
                ans = min(ans, road[2]);
        }
        return ans;
    }
};