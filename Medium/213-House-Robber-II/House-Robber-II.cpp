class Solution {
public:
    // This is a variation of the House Robber problem where the houses are arranged in a circle
    // The main challenge is that the first and last houses are adjacent, so we cannot rob both
    // To solve this, we can break the problem into two scenarios:
    // 1. Rob houses from index 0 to n-2 (excluding the last house)
    // 2. Rob houses from index 1 to n-1 (excluding the first house)
    // We then take the maximum of the two scenarios as the final result
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);
        return max(linearRob(nums,0,n-2),linearRob(nums,1,n-1));
    }
private:
    int linearRob(vector<int>& nums, int start, int end) {
        int current = 0, prev1 = 0, prev2 = 0;
        for(int i=start;i<=end;i++) {
            current = max(prev1, prev2+nums[i]);
            prev2 = prev1;
            prev1 = current;
        }
        return current;
    }
};