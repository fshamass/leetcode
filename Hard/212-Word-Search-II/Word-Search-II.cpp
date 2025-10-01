class Solution {
public:
    // THis is a challenging problem. It has several tricky parts and need to be thought through carefully.
    // The first part is to figure out how to search for words in board efficiently. Keep in mind that the
    // words can be formed in reverse order and also can overlap with each other. The best way to handle this
    // is by using DFS algorithm. You traverse the board and from each cell you do DFS in all 4 directions
    // The challenging part is to figure out how to keep track of adjacent characters that form a word.
    // That is, you are processing a character at a time and you need to know if that character is part of
    // one of the words in the list. and where that adjacent character is part of that word.
    // The best way to handle this efficiently is to use a Trie data structure.
    // The first step is to build Trie from the list of words where the root node children are the first 
    // character of each word in the list and each child node has it own children representing the next 
    // character in the word and so on. 
    // The Trie node contains a string variable that will hold the word if that node is at the end of the word. 
    // Otherwise, the string variable will be empty.
    // So now as we traverse the board and do DFS from each cell, we can go down the Trie as we traverse the 
    // board. If we encounter a node that has a non empty string variable, then we know we have found a word 
    // where all its characters are adjacent in the board. And so we add the word to the result and clear the 
    // string variable of the Trie node. 

    struct TrieNode {
        string word;
        unordered_map<char, TrieNode*> children;
        TrieNode() {
            word = "";
            for(int i=0;i<26;i++) {
                char ch = 'a' + i;
                children[ch] = nullptr;
            }
        }
    };

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        // Build the Trie from the word list
        TrieNode* root = buildTrie(words);
        
        // Traverse the board and do DFS from each cell
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                DFS(board, i, j, words, root, result);
            }
        }
        
        return result;
    }

private:
    TrieNode* buildTrie(const vector<string>& words) {
        // Create the root node of the Trie
        TrieNode* root = new TrieNode();
        // Traverse the list of words
        for(string word:words) {
            // At the start of each word, reset node to root
            TrieNode* node = root;
            // Traverse each character in the word
            for(char c:word) {
                // For each character, if it does not exist as child of current node, create a new TrieNode
                if(node->children[c] == nullptr) {
                    node->children[c] = new TrieNode();
                }
                // Move the node to the child node to drill down the Trie
                node = node->children[c];
            }
            // At the end of the word, set the word variable to indicate the end of the word
            node->word = word;
        }
        return root;
    } 

    void DFS(vector<vector<char>>& board, int i, int j, const vector<string>& words, TrieNode* node, vector<string>& result) {
        char c = board[i][j];
        // If the character is already visited or it does not exist as child, return
        if((c == '#') || (node->children[c] == nullptr)) {
            return;
        }

        // Mode node to the child node
        node = node->children[c];
        // If the word variable is not empty, we found a word, add it to the result
        if(!node->word.empty()) {
            result.push_back(node->word);
            node->word = "";
        }

        // Mark the character as visited by setting it to '#'
        // This is necessary to avoid cycles
        board[i][j] = '#';
        if(i>=1)DFS(board,i-1,j,words,node,result);
        if(j<board[0].size()-1) DFS(board,i  ,j+1,words,node,result);
        if(i<board.size()-1) DFS(board,i+1,j,words,node,result);
        if(j>=1) DFS(board,i  ,j-1,words,node,result);
        // Restore the character
        board[i][j] = c;
    }
};