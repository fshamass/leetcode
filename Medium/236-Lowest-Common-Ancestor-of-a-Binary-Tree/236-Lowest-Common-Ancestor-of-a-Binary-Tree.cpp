/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // The idea here is each call can either return nullptr, p, q, or the LCA node.
    // if branch contains neither p nor q, return nullptr.
    // if branch contains either p or q, return that node.
    // if left and right subtree both return non-null values, then this node is the LCA.

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if((root == nullptr) || (root == p) || (root == q)) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if((left) && (right)) { 
            return root;
        }
        return left ? left: right;
    }
};