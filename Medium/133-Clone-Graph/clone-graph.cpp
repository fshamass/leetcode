/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneNode(Node* node, unordered_map<Node*,Node*>& map) {
        if(!node) return nullptr;
        // First create the new node based on old node val
        Node* newNode = new Node(node->val);
        // Store the new node in hash table
        map[node] = newNode;
        // Populate the siblinks of the new node from old node siblink
        for(auto& neighbor:node->neighbors) {
            Node* n = nullptr;
            // If siblink does not exist, recall the function to create it and populate its siblinks
            if(map.count(neighbor) == 0) {
                n = cloneNode(neighbor,map);
            }else {
                n = map[neighbor];
            } 
            newNode->neighbors.push_back(n);
        }
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        //Key old node pointer and value is new node pointer
        unordered_map<Node*,Node*> nodeMap;
        Node* newRoot = cloneNode(node, nodeMap);
        return newRoot;
    }
};