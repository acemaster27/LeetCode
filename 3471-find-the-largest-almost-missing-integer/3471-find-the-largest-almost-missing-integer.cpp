class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int> ans(51, 0);
        for(int num : nums) {
            ans[num]++;
        }
        int  res = -1;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(k == n || (ans[nums[i]] == 1 && (k == 1 || i == 0 || i == n - 1)))
            res = max(res, nums[i]);
        }
        return res;
    }
};