class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        if(matrix[row - 1][col - 1] < target) return false;
        
        int left = 0, right = row - 1, index = 0;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(matrix[mid][0] <= target && matrix[mid][col - 1] >= target) {
                index = mid;
                break;
            }
            if(matrix[mid][col - 1] < target) left = mid + 1;
            else right = mid - 1;
        }
        
        left = 0, right = col - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(matrix[index][mid] == target) return true;

            if(target > matrix[index][mid]) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};