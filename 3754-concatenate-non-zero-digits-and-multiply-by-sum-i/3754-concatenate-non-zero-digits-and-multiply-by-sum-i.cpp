class Solution {
public:
    long long sumAndMultiply(int n) {
        if(!n) return 0;
        long long ans = 0;
        int exp = 0, sum = 0;
        while(n > 0) {
            int digit = n % 10;
            n /= 10;
            if(digit > 0) {
                ans += digit * pow(10, exp);
                exp++;
                sum += digit;
            }
        }
        return ans * sum;
    }
};