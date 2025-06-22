class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //Declare hash table for all available words
        unordered_set<string> dict;
        int maxLen = 0;

        //Insert available words and find length of longest word
        for(auto& word:wordDict) {
            dict.insert(word);
            maxLen = max(maxLen, static_cast<int>(word.length()));
        }

        vector<bool> dp(s.size()+1,false);
        dp[0] = true;

        //Index i will traverse through the string and will be used as an upper
        //Limit for words to be tested
        for(int i=1;i<= s.size();i++) {
            //Index j will be used to generate substrings from 0 (or if i is too large we go back as far as longest word)
            //to index i
            for(int j=max(0,i-maxLen);j<i;j++) {
                //If the generated substring is in hash table and the begining of
                //generated substring is also in hash table
                if((dp[j]) && (dict.find(s.substr(j,i-j)) != dict.end())) {
                    //Mark that upper limit of generated substrings as exist in hash table
                    dp[i] = true;
                    break;
                }
            }
        }
        //The last element of dp means all substrings exist in hash table
        return dp[s.size()];
    }
};