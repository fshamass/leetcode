class Solution {
public:
    // This problem has some tricks. The problem states that string t might have duplicates, so we
    // need to ensure the duplicates are also included in the string.
    // So what initially jumps to mind in to have hashtable for the characters that make up t string
    // We will also have another hash table for the characters that make up s string. 
    // Then we can have character sliding window (left and right pointers) and everytime we encounter
    // new character which also exists in t hashtable, we push it to s hashtable. 
    // Now the key question is, how do we check if current window contains all characters from t string?
    // Size of hash table tell us how may unique characters are in hash table but doesn't tell us anything
    // about the duplicates. If we subtract the size of hash table from the length of string (or window)
    // that tell us how many duplicates are there but not the number of duplicates for each character.
    // Off course we can check each element on both hash table duplication matches. However, doing this
    // comparison with every new character in s string is not an efficient solution especially if strings get
    // really long.
    // An efficient solution is to have a variable to keep track of how may character frequencies on both hash
    // tables are satisfied. that is, when we encounter new character in sliding window of s string, we check
    // if the frequency has reached the frequency of same character in t hash table, and only then we 
    // increment this variable. This way we can track if all characters and their frequencies in current sliding
    // window are matched in t hash table.

    string minWindow(string s, string t) {
        unordered_map<char,int> need, window;
        // Construct t hash table
        for(auto& ch:t) need[ch]++;
        int start=0,len=INT_MAX,left=0,right=0,validLen=0;
        while(right<s.size()) {
            // for each new character in sliding window
            char ch = s[right];
            right++;
            // Increment its frequencies in s hash table
            window[ch]++;
            // If character frequencies in both hash table match, increment variable
            if((need.count(ch)) && (need[ch] == window[ch])) validLen++;
            // Since each count increment in variable means character frequency match, then
            // if variable equals size of the t hash table, then all characters in t exist in current window
            while(validLen == need.size()) {
                // Check and update minimum
                int tmp = right-left;
                if(tmp < len) {
                    len = tmp;
                    start = left;
                }
                // To try new window, we can increment left pointer but since that character that we are
                // moving away from might be in t hash table, that will break the condition that current 
                // window covers all characters. Therefore, we need to decrement the variable to indicate
                // that one of the t character frequencies is not covered bu current window
                if((need.count(s[left])) && (window[s[left]] == need[s[left]])) {
                    validLen--;
                }
                window[s[left]]--;
                left++;
            }
        }
        string ret = (len == INT_MAX) ? "":s.substr(start,len);
        return ret;
    }
};