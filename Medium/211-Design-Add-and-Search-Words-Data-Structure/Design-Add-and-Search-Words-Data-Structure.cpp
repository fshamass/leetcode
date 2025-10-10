class WordDictionary {
public:
    // This is a challenging Trie implementation. The main challenge is in searching for words
    // The add word is straight forward, we simply insert the word into the Trie character by character
    // The search is the challenging part because of the '.' character which can represent any character
    // The idea is to use recursion to search for the word character by character
    // If the character is not '.', we simply move to the child node that represents that character
    // If the character is '.', we need to check all possible children of the current node
    // and recursively search for the rest of the word in each child node
    
    struct TrieNode {
        unordered_map<char,TrieNode*> children;
        bool endOfStr;
        TrieNode(): endOfStr(false) {}
    };
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (auto ch : word) {
            if (node->children.count(ch) == 0) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->endOfStr = true;
    }
    
    bool search(string word) {
        return searchInNode(word, 0, root);
    }
private:
    TrieNode* root;
    bool searchInNode(const string& word, int index, TrieNode* node) {
        // Base case: we've reached the end of the word
        if (index == word.size()) {
            return node->endOfStr;
        }
        
        char currentChar = word[index];
        
        // If the current character is not a dot
        if (currentChar != '.') {
            // If the character exists in children, continue searching
            if (node->children.count(currentChar)) {
                return searchInNode(word, index + 1, node->children[currentChar]);
            }
            return false;
        } 
        // If the current character is a dot, we need to check all children since '.' can represent any character
        else {
            // Check all possible children
            for (auto& child : node->children) {
                // If any path leads to a valid word, return true
                if (searchInNode(word, index + 1, child.second)) {
                    return true;
                }
            }
            return false;
        }
    }    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */