class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        queue<int> q;
        for(auto it : pre) {
            indegree[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }
        int result = 0;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                result++;
            }
        }
        while(!q.empty()) {
            int course = q.front();
            q.pop();
            for(int i : adj[course]) {
                indegree[i]--;
                if(indegree[i] == 0) {
                    q.push(i);
                    result++;
                }
            }
        }
        if(result == numCourses) return true;
        return false;
    }
};