class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int even = 0, odd = 0, temp = INT_MAX;
        for(int num : nums1) {
            if(num % 2 == 0) even++;
            else {
                odd++;
                temp = min(temp, num);
            }
        }
        if(even == 0 || odd == 0) return true;
        for(int num : nums1) {
            if(num % 2 == 0 && num < temp) return false;
        }
        return true;
    }
};