class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Strategy: Use Kudane's algorithm to find the maximum subarray sum in linear time.
        //Set both the initial sum and maxSum to the first element of the array.
        int sum = nums[0];
        int maxSum =  nums[0];
        // Iterate through the array starting from the second element.
        // For each element, update the sum to be either the current element or the sum of the current element and the previous sum.
        // Update maxSum to be the maximum of itself and
        for(int i=1;i<nums.size();i++) {
            sum = max(nums[i], sum + nums[i]);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};