class Solution {
public:
    // The idea here is to iterate through the list of prices while keeping track of the minimum price encountered so far.
    // For each price, calculate the potential profit by subtracting the minimum price from the current price.
    // Update the maximum profit whenever we find a higher potential profit.
    // This approach ensures we only traverse the list once, achieving O(n) time complexity.

    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for(auto& price:prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price-minPrice);
        }
        return maxProfit;
    }
};