class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0], end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] <= end) end = max(intervals[i][1], end);
            else {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};