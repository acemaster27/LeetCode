class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty()) return {};
        map<int, int> m;
        for(auto num : arr) {
            m[num] = -1;
        }
        int i = 1;
        for(auto &entry : m) {
            entry.second = i++;
        }
        for(auto &num : arr) {
            num = m[num];
        }
        return arr;
    }
};