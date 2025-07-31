class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Anagrams yield same string if sorted, so we can use that property to group them.
        // Strategy: Use a hash table where the key is the sorted version of the string and 
        // the value is a vector of strings that when sorted, result in string used as key.
        // Finally we will iterate through the hash table and push the value of each key (which 
        // is a vector of anagrams) to the result vector.
        vector<vector<string>> res;
        unordered_map<string,vector<string>> strMap;
        for(auto& str:strs) {
            // Grab each string in strs input
            string tmp = str;
            // Sort the string to use it as a key
            sort(tmp.begin(),tmp.end());
            // push the original string not sorted version to maintain the original strings
            strMap[tmp].push_back(str);
        }
        for(auto itr = strMap.begin();itr !=strMap.end();itr++) {
            // Value of key is vector of anagrams, so we push it to the result vector
            res.push_back(itr->second);
        }
        return res;
    }
};