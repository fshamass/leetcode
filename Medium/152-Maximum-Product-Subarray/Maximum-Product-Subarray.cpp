class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        //Strategy: Use dynamic programming to keep track of the maximum and minimum product subarrays ending at each index.
        //The minimum product is needed because a negative number can turn a small product into a large product when multiplied by another negative number.
        int maxSum = nums[0];
        int minSum = nums[0];
        int result = nums[0];

        for(int i=1;i<nums.size();i++) {
            // If the current number is negative, swap maxSum and minSum
            // because multiplying by a negative number will turn the maximum into a minimum and vice versa.
            // This is crucial for handling negative numbers correctly.
            if(nums[i] < 0) swap(maxSum, minSum);
            // Update maxSum and minSum
            maxSum = max(nums[i], maxSum * nums[i]);
            minSum = min(nums[i], nums[i] * minSum);
            // Update the result with the maximum product found so far
            result = max(result,maxSum);
        }
        return result;
    }
};