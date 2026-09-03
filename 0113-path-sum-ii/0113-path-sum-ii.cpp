/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void Solve(TreeNode* root, int& targetSum, vector<vector<int>>& ans, vector<int> temp, int current) {
            current += root -> val;
            temp.push_back(root -> val);
            if(!root -> left && !root -> right) {
                if(current == targetSum)
                ans.push_back(temp);
            }
            else {
                if(root -> left) Solve(root -> left, targetSum, ans, temp, current);
                if(root -> right) Solve(root -> right, targetSum, ans, temp, current);
            }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        if(root != nullptr)
        Solve(root, targetSum, ans, temp, 0);
        return ans;
    }
};