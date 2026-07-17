class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto time : times) {
            adj[time[0]].push_back({time[1], time[2]});
        }
        vector<int> dist(n + 1, 1e8);
        dist[0] = 0;
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, k});
        while(!minHeap.empty()) {
            int travel = minHeap.top().first;
            int current = minHeap.top().second;
            minHeap.pop();
            if(travel > dist[current]) continue;
            for(auto edge : adj[current]) {
                int neighbour = edge.first;
                int value = edge.second;
                if(travel + value < dist[neighbour]) {
                    dist[neighbour] = travel + value;
                    minHeap.push({dist[neighbour], neighbour});
                }
            }
        }
        int ans = *max_element(dist.begin(), dist.end());
        return ans == 1e8 ? -1 : ans;
    }
};