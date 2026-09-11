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
    void Solve(TreeNode* root, int sum, int& ans) {
        sum = sum * 10 + root -> val;
        if(!root -> left && !root -> right) {
            ans += sum;
            return;
        }
        if(root -> left) Solve(root -> left, sum, ans);
        if(root -> right) Solve(root -> right, sum, ans);
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        Solve(root, 0, ans);
        return ans;
    }
};