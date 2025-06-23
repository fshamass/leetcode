class Solution {
public:
    int missingNumber(vector<int>& nums) {
        size_t size = nums.size();
        //Strategy is summation of any sequence of n numbers = n*(n+1)/2
        //By up summing all elements of the array and subtracting it from n*(n-1)/2 
        //The difference is the missing number
        long long expectedSum = static_cast<long long>(size) * (size +1)/2;
        long long sum = 0;
        for(auto& num:nums) sum += num;
        return static_cast<int>(expectedSum - sum);
    }
};