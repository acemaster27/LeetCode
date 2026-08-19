class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = 2 * n;
        unordered_map<int, int> theatre;
        for(auto &seat : reservedSeats) {
            theatre[seat[0]] |= (1 << seat[1]);
        }
        for(auto &[row, code] : theatre) {
            bool left = (0b0000111100 & code) == 0;
            bool right = (0b1111000000 & code) == 0;
            bool middle = (0b0011110000 & code) == 0;
            if(left && right) continue;
            else if(left || right || middle) ans--;
            else ans -= 2;
        }
        return ans;
    }
};