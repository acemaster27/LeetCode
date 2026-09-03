class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int even = 0, tempOdd = INT_MAX, tempEven = INT_MAX;
        for(int num : nums1) {
            if(num % 2 == 0) {
                even++;
                tempEven = min(tempEven, num);
            }
            else {
                tempOdd = min(tempOdd, num);
            }
        }
        if(even == 0 || even == nums1.size() || tempOdd < tempEven) return true;
        return false;
    }
};