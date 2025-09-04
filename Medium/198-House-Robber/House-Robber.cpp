class Solution {
public:
    // This is a classic dynamic programming problem od testing whether including or excluding 
    // the current element. Since we cannot rob two adjacent houses, and it is a maximizing problem,
    // then it becomes the question of what is maximum profit from the following two scenarios:
    // 1. Robbing this house and adding the profit from it to the profit from house adjacent to 
    // prior house (i.e. skipping the previous house) 
    // 2. skip robbing the current house and keep profit obtained from robbing previous house
    // Return the profit from last house since it contains the maximum profit from all houses
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, 0);
        if(nums.size() == 0) return 0;
        dp[1] = nums[0];
        for(int i=2;i<=nums.size();i++) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
        }
        return dp[nums.size()];
    }
}