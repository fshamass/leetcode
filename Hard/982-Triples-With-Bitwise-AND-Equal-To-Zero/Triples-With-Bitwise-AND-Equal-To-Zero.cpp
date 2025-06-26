class Solution {
public:
    int countTriplets(vector<int>& nums) {
        // Strategy is to find the frequency of bitwise AND of each pair of numbers
        // and then check how many of these pairs can form a triplet that AND to zero with each number
        int count = 0;
        unordered_map<int,int> freq;
        for(auto& i:nums) {
            for(auto& j:nums) {
                int tmp = i & j;
                freq[tmp]++;
            }
        }
        for(auto& num:nums) {
            for(auto& f:freq) {
                if((num & f.first) == 0) count+= f.second;
            }
        }
        return count;
    }
};