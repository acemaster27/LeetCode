class Solution {
public:
    vector <int> nextSmallerElement(vector <int> &heights, int n) {
        vector <int> ans(n);
        stack <int> s;
        s.push(-1);
        for(int i = n-1; i >= 0; i--) {
            int num = heights[i];
            while(s.top() != -1 && heights[s.top()]>= num) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector <int> prevSmallerElement(vector <int> &heights, int n) {
        stack <int> s;
        vector <int> ans(n);
        s.push(-1);
        for(int i = 0; i < n; i++) {
            int num = heights[i];
            while(s.top() != -1 && heights[s.top()]>=num) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0, area = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        vector<int> prev, next;

        for(int i = 0; i < rows; i++) {
            area = 0;
            for(int j = 0; j < cols; j++) {
                if(matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            prev = prevSmallerElement(heights, cols);
            next = nextSmallerElement(heights, cols);
            for(int i = 0; i < cols; i++) {
                if(next[i] == -1) next[i] = cols;
                int b = next[i] - prev[i] - 1;
                int l = heights[i];
                area = l * b;
                maxArea = max(area, maxArea);
            }
        }
        return maxArea;
    }
};