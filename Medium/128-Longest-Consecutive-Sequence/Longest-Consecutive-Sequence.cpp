class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        // Initially store all array elements in a set for efficient future search 
        unordered_set<int> seq(nums.begin(),nums.end());
        int cnt = 0;
        int maxCnt = 0;
        for(auto num:nums) {
            //check if it is start of a sequence. 
            // If this number is part of sequence, there will be (number -1) in hash table
            if(seq.find(num-1) == 0) {
                cnt = 1;
                // if this is start of sequence, find out how many subsequent numbers exist in array
                while(seq.find(num+1) != seq.end()) {
                    num++;
                    cnt++;
                }
                //Update max length
                maxCnt = max(maxCnt, cnt);
            }
        }
        return maxCnt;
    }
};
