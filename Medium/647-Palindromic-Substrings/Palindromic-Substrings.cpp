class Solution {
public:
    int expandAroundCenter(string& str, int left, int right) {
        int ret = 0;
        // Increment number of palindroms as long as the characters pointed to by left and right pointers match
        // Even 1 character is considered a plaindrom
        while((left>= 0) && (right<str.length()) && (str[left] == str[right])) {
            left--;
            right++;
            ret++; 
        }
        return ret;
    }
    int countSubstrings(string s) {
        int ret = 0;
        int n = s.length();
        for(int i=0;i<n;i++) {
            //Count without including current character
            ret += expandAroundCenter(s,i-1,i+1);
            //Count with current character
            ret += expandAroundCenter(s,i,i+1);
            //We don't need to run (s,i-1,i) because it is already counted in previous i
            //For instance, if i = 1, then running (s,i,i+1) will result in (s,1,2)
            //When i = 2, running (s,i-1,i) will be result in (s,1,2) which is already handled in previous i
        }
        ret += n;
        return ret;
    }
};