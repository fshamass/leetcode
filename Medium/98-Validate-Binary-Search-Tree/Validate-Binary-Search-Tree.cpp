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
    // To validate a binary search tree (BST), we need to ensure that for every node,
    // all values in its left subtree are less than the node's value, and all values
    // in its right subtree are greater than the node's value.
    // We can achieve this by using a helper function that takes a node and the valid
    // range (min and max values) for that node. Initially, the range is set to
    // negative infinity and positive infinity.
    // As we traverse the tree, we update the range for each subtree.
    // If we find any node that violates the BST properties, we return false.   
    // This problem can also be solved using inorder traversal to check if the values are in sorted order.

    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        return isSubtreeValid(root, LONG_MIN, LONG_MAX);
    }
private:
    // Helper function to validate the subtree
    // Notice min and max are of type long to handle edge cases with INT_MIN and INT_MAX
    bool isSubtreeValid(TreeNode* root, long min, long max) {
        if(root == nullptr) return true;

        // Check if the current node's value is within the valid range
        // Notice the use of equality to handle duplicates which are not allowed in BST
        if((root->val <= min) || (root->val >= max)) return false;
        return isSubtreeValid(root->left,min, root->val) &&
            isSubtreeValid(root->right, root->val, max);
    }
};