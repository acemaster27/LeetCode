class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], current = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            current = max(current + nums[i], nums[i]);
            ans = max(current, ans);
        }
        return ans;
    }
};