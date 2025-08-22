class Solution {
public:
    // For this problem the easiest way to solve it is to use dynamic programming
    // This idea is to create a 2D array where each element dp[i][j] represents 
    // the number of ways to reach that element from the starting point (0,0)
    // The first row and the first column should be set to 1. this is very confusing
    // to some engineers but the reason is, there is only one way to reach any element
    // in the first row or the first column, that is to move either right or down
    // then since we can only move either right or down, the number of ways to reach
    // any other element is the sum of the number of ways to reach the element directly
    // above it and the element directly to the left of it.
    // We finally return the value at the bottom right corner since it represents the 
    // destination point in the grid
    
    int uniquePaths(int m, int n) {
        if((m==1)&&(n==1)) return 1;
        vector<vector<int>> dp(m,vector<int>(n,1));
        dp[0][0] = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if((i > 0) && (j > 0)) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};