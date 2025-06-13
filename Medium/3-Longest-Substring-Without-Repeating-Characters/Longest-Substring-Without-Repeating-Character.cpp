class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxLen = 0;
        unordered_map<char,int> chars;
        int index = 0;
        while(index < s.length()) {
            auto itr = chars.find(s[index]);
            if((itr != chars.end()) && (itr->second >= left)) {
                left = itr->second + 1;
                itr->second = index;
            } else {
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
