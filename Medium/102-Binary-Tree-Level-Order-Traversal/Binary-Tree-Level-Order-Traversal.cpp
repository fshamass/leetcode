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
    // This is a straightforward level order traversal using a queue.
    // We start by pushing the root node into the queue.
    // Then, while the queue is not empty, we process each level of the tree.
    // For each level, we determine the number of nodes at that level (size of the queue).
    // We then iterate through these nodes, popping them from the queue, adding their values
    // to a temporary vector, and pushing their children (if any) into the queue.
    // After processing all nodes at the current level, we add the temporary vector to the result.
    // Finally, we return the result which contains the level order traversal of the tree.
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> level;
            int size = q.size();
            for(int i=0;i<size;i++) {
                TreeNode* front = q.front();
                q.pop();
                if(front->left)  q.push(front->left);
                if(front->right) q.push(front->right);
                level.push_back(front->val);
            }
            result.push_back(level);
        }
        return result;
    }
};