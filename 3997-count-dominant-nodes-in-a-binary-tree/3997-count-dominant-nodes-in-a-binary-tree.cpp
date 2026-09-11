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
    int Solve(TreeNode* root, int& count) {
        if(root == nullptr) return 0;
        int left = Solve(root -> left, count);
        int right = Solve(root -> right, count);
        if(root -> val >= max(left, right)) {
            count++;
        }
        return max({root -> val, left, right});
    }
    int countDominantNodes(TreeNode* root) {
        int count = 0;
        Solve(root, count);
        return count;
    }
};