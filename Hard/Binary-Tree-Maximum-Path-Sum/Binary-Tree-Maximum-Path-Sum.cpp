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
    // The approach here is to perform a depth-first traversal of the binary tree.
    // For each node, we calculate the maximum path sum that can be obtained including that node.
    // We consider paths that go through the left and right children, updating the global maximum path sum accordingly.
    // The function returns the maximum path sum that can be obtained from the current node to its parent.
    // This ensures that we explore all possible paths in the tree
    int nextNode(TreeNode* node, int& maxSum) {
        if(!node) return INT_MIN;
        maxSum = max(maxSum, node->val);
        int sum = node->val;
        int left = nextNode(node->left, maxSum);
        if(left != INT_MIN) {
            maxSum = max(maxSum, node->val + left);
            sum += left;
        }
        int right = nextNode(node->right,maxSum);
        if(right != INT_MIN) {
            maxSum = max(maxSum, node->val + right);
            sum += right;
        }
        maxSum = max(maxSum, sum);
        return node->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int sum = nextNode(root, maxSum);
        return maxSum;
    }
};