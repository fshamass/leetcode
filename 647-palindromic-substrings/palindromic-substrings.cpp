class Solution {
public:
    int expandAroundCenter(string& str, int left, int right) {
        int ret = 0;
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
            ret += expandAroundCenter(s,i-1,i+1);
            ret += expandAroundCenter(s,i,i+1);
        }
        ret += n;
        return ret;
    }
};