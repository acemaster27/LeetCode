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
    pair<int, int> Solve(TreeNode* root, int& ans) {
        if(root == nullptr) return {0, 0};
        auto left = Solve(root -> left, ans);
        auto right = Solve(root -> right, ans);
        int sum = left.second + right.second + root -> val;
        int count = left.first + right.first + 1;
        if(sum / count == root -> val)
        ans++;
        return {count, sum};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        Solve(root, ans);
        return ans;
    }
};