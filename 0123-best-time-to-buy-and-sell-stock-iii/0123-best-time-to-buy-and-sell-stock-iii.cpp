class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> first(n, 0), second(n, 0);
        int minPrice = prices[0];
        for(int i = 1; i < n; i++) {
            minPrice = min(prices[i], minPrice);
            first[i] = max(first[i - 1], prices[i] - minPrice);
        }

        int maxPrice = prices[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            maxPrice = max(maxPrice, prices[i]);
            second[i] = max(second[i + 1], maxPrice - prices[i]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, first[i] + second[i]);
        }
        return ans;
    }
};