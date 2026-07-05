class Solution {
public:
struct dsu {
    vector<int> parent;
    dsu(int n) {
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    bool unity(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) {
            parent[b] = a;
            return true;
        }
        return false;
    }
};
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> root(n + 1, 0);
        vector<int> one, two;
        for(auto &edge : edges) {
            int first = edge[0];
            int second = edge[1];
            if(root[second] == 0) {
                root[second] = first;
            } else {
                one = {root[second], second};
                two = {first, second};

                edge[1] = 0;
            }
        }
        
        dsu d(n);
        for(auto &edge : edges) {
            int first = edge[0];
            int second = edge[1];

            if(edge[1] == 0) continue;
            if(!d.unity(first, second)) {
                if(one.empty()) return edge;
                else return one;
            }
        }
        return two;
    }
};