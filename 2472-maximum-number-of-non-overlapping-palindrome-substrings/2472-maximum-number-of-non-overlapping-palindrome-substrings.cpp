class Solution {
public:
    bool isPal(int left, int right, string& s) {
        for(;left < right;) {
            if(s[left] == s[right]) {
                left++;
                right--;
            } else {
                return false;
            }
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int n = s.length();
        if(k == 1) return n;
        int index = 0, ans = 0;
        for(int right = k - 1; right < n; right++) {
            int left = right - k + 1;
            if((left >= index && isPal(left, right, s)) || (left > index && isPal(left - 1, right, s))) {
                ans++;
                index = right + 1;
            }
        }
        return ans;
    }
};