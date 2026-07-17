class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()) {
            int index = nums[i] - 1;
            if(nums[i] != nums[index]) swap(nums[i], nums[index]);
            else i++;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i + 1) return nums[i];
        }
        return -1;
    }
};