class Solution {
public:
    // 1,000,000,000,000,000
    long long countCommas(long long n) {
        return max(n - 999, 0LL) + max(n - 999999, 0LL) + max(n - 999999999, 0LL) + max(n - 999999999999, 0LL) + max(n - 999999999999999, 0LL);
    }
};