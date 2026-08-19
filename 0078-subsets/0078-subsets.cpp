class Solution {
public:
    void Solve(vector<int> &nums, vector<int> &temp, int start, vector<vector<int>> &ans) {
        ans.push_back(temp);
        for(int i = start; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            Solve(nums, temp, i + 1, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        Solve(nums, temp, 0, ans);
        return ans;
    }
};