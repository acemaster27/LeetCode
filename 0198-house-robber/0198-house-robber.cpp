class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev1 = 0, prev2 = 0;
        for(int num : nums) {
            int current = max(prev2 + num, prev1);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};