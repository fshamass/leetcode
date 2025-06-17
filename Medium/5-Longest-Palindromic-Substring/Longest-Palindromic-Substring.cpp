class Solution {
public:
//Helper function to return the location of palindrom start and length of palindrom
    pair<int,int> findPal(string& str, int left, int right) {
        // initialize length to 1 since one character is basically a palindrom
        int len = 1;
        // Loop as long as indices are valid and characters on both ends match
        while((left >=0) && (right < str.length()) && (str[left] == str[right])) {
            left--;
            right++;
        }
        // at this point left is 1 index lower than last match and right is 
        // one index higher of last match
        // length will be the difference betwee the 2 ends but you need to subtract 1 since we need 
        // to exclude both of the indices
        // since left is i index lower that last match, then start will be that last match left +n1
        return {right-left-1,left+1};
    }

    string longestPalindrome(string s) {
        int maxLen = 0;
        int strStart = 0;
        for(int i=0;i<s.length();i++) {
            // account for both odd and even length strings
            auto odd = findPal(s,i,i);
            auto even = findPal(s, i, i +1);
            // update maxLen and start of palindrom based
            if(odd.first > maxLen) {
                maxLen = odd.first;
                strStart = odd.second;
            }
            if(even.first > maxLen) {
                maxLen = even.first;
                strStart = even.second;
            }
        }
        // build palindrom string from max start and length
        string res = s.substr(strStart, maxLen);
        return res;
    }
};