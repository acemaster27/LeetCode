class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int first = 0, second = 0;
        for(int i = 2; i < nums.size(); i++) {
            if(arr1[first] > arr2[second]) {
                arr1.push_back(nums[i]);
                first++;
            } else {
                arr2.push_back(nums[i]);
                second++;
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};