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
    bool isSame(TreeNode* a, TreeNode* b) {
        return a -> val == b -> val;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(isSame(p, q)) {
            if((p -> left == nullptr ^ q -> left == nullptr) || (p -> right == nullptr ^ q -> right == nullptr)) return false;
            bool check1 = true, check2 = true;
            if(p -> left && q -> left)
            check1 = isSameTree(p -> left, q -> left);
            if(p -> right && q -> right)
            check2 = isSameTree(p -> right, q -> right);
            if(check1 && check2)
            return true;
            else 
            return false; 
        } 
        else 
        return false;
    }
};