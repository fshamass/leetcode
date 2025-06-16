class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxLen = 0;
        // Hash table to store the lase seen character if any
        unordered_map<char,int> chars;
        int index = 0;
        while(index < s.length()) {
            // Have we seen this character before? if so, where?
            auto itr = chars.find(s[index]);
            // if we have seen this character before and it was located at index greater than left pointer
            if((itr != chars.end()) && (itr->second >= left)) {
                // Move left pointer to index to the right of last seen character
                left = itr->second + 1;
                itr->second = index;
            } else {
                // Calcuate window length and update max length if necessary
                int len = index -left+1;
                if(len > maxLen) {
                    maxLen = len;
                }
            }
            chars[s[index]] = index;
            index++;
        }
        return maxLen;
    }
};
