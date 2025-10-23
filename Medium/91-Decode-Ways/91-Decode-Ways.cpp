#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    //The problem can be either solved by recursion or dynamic programming. I will use dynamic programming here.
    //The idea is to use a dp array where dp[i+1] represents the number of ways to decode the substring s[0..i].
    //We initialize dp[0] = 1 since an empty string has one way to decode.
    //Then we traverse through the string and for each character in the string, we check if it can form a valid 
    //single-digit decode (1-9) and a valid two-digit decode (10-26) with the previous character.
    //We update the dp array accordingly.
    //Finally, dp[n] will contain the total number of ways to decode the entire string.

    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        // dp[i+1] means the number of ways to decode s[0..i]
        for (int i = 0; i < n; ++i) {
            //If current character is not '0', it can be decoded as a single digit
            if (s[i] != '0') {
                dp[i + 1] += dp[i];
            }
            //For tow digit decode, we must ensure that i > 0 to have a previous character
            if (i > 0) {
                //Form the two digit number of current and previous character
                int twoDigit = (s[i - 1] - '0') * 10 + (s[i] - '0');
                // If the two digit number is between 10 and 26, it can be decoded as a valid character
                if (twoDigit >= 10 && twoDigit <= 26) {
                    //add the number of ways to decode up to the character before the previous one
                    dp[i + 1] += dp[i - 1];
                }
            }
        }
        
        return dp[n];
    }
};