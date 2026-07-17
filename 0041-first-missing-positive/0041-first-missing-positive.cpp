class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0, mini = nums[0], n = nums.size();
        for(int i = 0; i < n; i++) {
            mini = min(mini, nums[i]);
        }
        while(i < n) {
            if(nums[i] <= 0 || nums[i] > n) {
                i++;
                continue;
            }
            int index = nums[i] - 1;
            if(nums[i] != nums[index]) swap(nums[i], nums[index]);
            else i++;
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};