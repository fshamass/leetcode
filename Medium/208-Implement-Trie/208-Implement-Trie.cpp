class Trie {
public:
    // This is a standard Trie implementation using unordered_map to hold children of each node
    // Each level contains a character from string being inserted. The last character node of the string
    // contains a boolean variable to indicate that it is the last character of the string.
    struct TrieNode{
        unordered_map<char,TrieNode*> children;
        bool lastChar = false;
    };
    TrieNode* root;
    Trie() {
        root = new TrieNode;
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(char ch:word){
            if(node->children.count(ch) == 0) {
                node->children[ch] = new TrieNode;
            }
            node = node->children[ch];
        }
        node->lastChar = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char ch:word) {
            if(node->children.count(ch) == 0) {
                return false;
            }
            node = node->children[ch];
        }
        if(node->lastChar == true) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char ch:prefix) {
            if(node->children.count(ch) == 0) return false;
            node = node->children[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */