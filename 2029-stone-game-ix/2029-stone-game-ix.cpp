class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> wt(3, 0);
        for(int stone : stones) {
            wt[stone % 3]++;
        }
        if(wt[0] & 1) {
            return abs(wt[1] - wt[2]) >= 3;
        } else {
            return min(wt[1], wt[2]) >= 1;
        }
        
    }
};