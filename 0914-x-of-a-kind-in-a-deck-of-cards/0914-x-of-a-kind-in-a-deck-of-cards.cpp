class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m;
        for(auto card : deck) m[card]++;
        int count = 0;
        for(auto it : m) {
            count = gcd(count, it.second);
            if(count < 2) return false;
        }
        return true;
    }
};