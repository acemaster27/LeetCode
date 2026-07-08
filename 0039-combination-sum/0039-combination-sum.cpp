class Solution {
public:
    void Solve(vector<int>& candidates, int& target, vector<vector<int>> &ans, vector<int> &temp, int index, int sum) {
        if(sum == target) {
            ans.push_back(temp);
            return;
        }
        for(int i = index; i < candidates.size(); i++) {
            if(sum + candidates[i] <= target) {
                sum += candidates[i];
                temp.push_back(candidates[i]);
                Solve(candidates, target, ans, temp, i, sum);
                sum -= candidates[i];
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        Solve(candidates, target, ans, temp, 0, 0);
        return ans;
    }
};