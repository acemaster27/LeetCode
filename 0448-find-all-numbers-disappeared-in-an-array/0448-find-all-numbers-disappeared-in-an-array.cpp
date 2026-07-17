class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int i = 0;
        while(i < nums.size()) {
            int index = nums[i] - 1;
            if(nums[i] != nums[index]) swap(nums[i], nums[index]);
            else i++;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i + 1) ans.push_back(i + 1);
        }
        return ans;
    }
};