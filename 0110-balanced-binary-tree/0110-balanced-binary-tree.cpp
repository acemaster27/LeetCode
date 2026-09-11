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
    int Solve(TreeNode* root, bool& ans) {
        if(root == nullptr || !ans) return 0;
        int left = Solve(root -> left, ans);
        int right = Solve(root -> right, ans);
        if(abs(left - right) > 1) {
            ans = false;
        }
        return max(left, right) + 1;
        
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        bool ans = true;
        Solve(root, ans);
        return ans;
    }
};