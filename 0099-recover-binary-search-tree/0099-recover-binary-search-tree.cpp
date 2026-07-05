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
    TreeNode* first;
    TreeNode* second;
    void Traverse(TreeNode* root, vector<TreeNode*> &temp) {
        if(root == nullptr) return;
        if(root -> left) Traverse(root -> left, temp);
        temp.push_back(root);
        if(root -> right) Traverse(root -> right, temp);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> temp;
        Traverse(root, temp);
        vector<int> dummy;
        for(auto node : temp) {
            dummy.push_back(node -> val);
        }
        sort(dummy.begin(), dummy.end());
        for(int i = 0; i < temp.size(); i++) {
            if(temp[i] -> val != dummy[i]) {
                if(first == nullptr) first = temp[i];
                else second = temp[i];
            }
        }
        swap(first -> val, second -> val);
    }
};