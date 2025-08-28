/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // For this problem, it's obvious that serializing the tree would involve creating a string
    // representation of the tree. We add stringify the value of each node we encounter followed 
    // by comma or any other delimiter. For null nodes we can use a special string like "nullptr"
    // to represent null nodes. 
    // Now the most important part is to figure out how to traverse the tree. We can use either
    // BFS or DFS. and for DFS, we need to choose preorder, inorder, or post order traversals.
    // When making that decision, we have to think about how easy it is to deserialize and restore
    // the structure of the original tree. 
    // I chose DFS traversal because it's easy to implement using recursion and I chose preorder 
    // traversal because it best represents the tree structure. 
    // Now that we have an idea of how the serialized string would look like (nodes value or nullptr
    // separated by comma), we can think about how to deserialize the string back to the original tree
    // structure. That should be straight forward since we know the preorder traversal of the tree
    // the first value in the string is the root node, then the next value is the left child of the root
    // and the next value after that is the right child of the root and so on.  

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // Handle the edge case of empty tree
        if(!root) return "";
        // Use ostringstream to build the serialized string
        ostringstream os;
        preorder(root, os);
        return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // Handle the edge case of empty string
        if(data.length() == 0) return nullptr;
        // Use istringstream to read the serialized string
        istringstream is(data);
        TreeNode* root = deserializeHelper(is);
        return root;
    }

private:
    void preorder(TreeNode* root, ostringstream& os) {
        if(!root) {
            os << "nullptr,";
            return;
        }
        os << root->val << ",";
        preorder(root->left, os);
        preorder(root->right, os);    
    }

    TreeNode* deserializeHelper(istringstream& is) {
        string val;
        //use getline to read up to the next comma, very convenient function
        getline(is, val, ',');
        if(val == "nullptr") return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserializeHelper(is);
        root->right = deserializeHelper(is);
        return root;
    }
};
