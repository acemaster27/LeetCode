class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxR = nums[0];
        for(int i = 0; i <= maxR; i++) {
            maxR = max(maxR, i + nums[i]);
            if(maxR >= nums.size() - 1) return true;
        }
        return false;
    }
};