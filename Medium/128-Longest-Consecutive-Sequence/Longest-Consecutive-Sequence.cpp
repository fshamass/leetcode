class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        unordered_set<int> seq(nums.begin(),nums.end());
        int cnt = 0;
        int maxCnt = 0;
        for(auto num:nums) {
            //check if it is start of a sequence
            if(seq.find(num-1) == 0) {
                cnt = 1;
                while(seq.find(num+1) != seq.end()) {
                    num++;
                    cnt++;
                }
                maxCnt = max(maxCnt, cnt);
            }
        }
        return maxCnt;
    }
};
