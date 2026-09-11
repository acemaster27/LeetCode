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
    void Solve(TreeNode* root, vector<int>& ans, int level, int& maxReach) {
        if(root == nullptr) return;
        if(level > maxReach) {
            maxReach = level;
            ans.push_back(root -> val);
        }
        Solve(root -> right, ans, level + 1, maxReach);
        Solve(root -> left, ans, level + 1, maxReach);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int maxReach = 0;
        Solve(root, ans, 1, maxReach);
        return ans;
    }
};