class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[0] + nums[1] + nums[2];
        int minimum = abs(target - ans);
        for(int i = 0; i < n - 2; i++) {
            for(int j = i + 1; j < n - 1; j++) {
                for(int k = j + 1; k < n; k++) {
                    if(abs(nums[i] + nums[j] + nums[k] - target) < minimum) {
                        minimum = abs(nums[i] + nums[j] + nums[k] - target);
                        ans = nums[i] + nums[j] + nums[k];
                    }
                }
            }
        }
        return  ans;
    }
};