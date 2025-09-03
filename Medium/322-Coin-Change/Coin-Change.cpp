class Solution {
public:
    // This is a typical dynamic programming problem of include vs exclude the element (coin in this case)
    // The idea is to use an array dp where dp[i] represents the minimum number of coins needed to make amount i.
    // Then for each coin, we examine whether including or excluding the coin would yield less number of coins.
    // Then we set dp[i] to the minimum of its current value (excluding the coin yields less coins to make up the 
    // amount) or including the coin (in this case we will reduce the examined amount by the value of the coin and 
    // then see the minimum coins needed to make the remaining amount). If the later turns out to give less coins,
    // then we update dp[i] to be the number of coins needed for the remainder amount (dp[i-coin]) and we add 1 to
    // it to account for the current coin.
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        // The reason we initialize the dp array with amount+1 is we choose uniquely large number that is greater than 
        // any possible number of coins needed to make up the amount. This way, if we find a solution, it will be less 
        // than amount+1 and we can return it. Otherwise, if we never find a solution, we can return -1.
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(int i=1;i<=amount;i++) {
            for(auto&coin:coins) {
                if(coin <= i) {
                    dp[i] = min(dp[i], dp[i-coin]+1);
                }
            }
        }
        return ((dp[amount] < amount+1)? dp[amount]:-1);
    }
};