class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //Strategy is to sort the array and use two pointers to find pairs that sum to the negative of the current number
        //This avoids the need for a nested loop and allows us to skip duplicates easily
        if(nums.size() < 3) return {}; // Early return if not enough elements
        if(nums.size() == 3) {
            if(nums[0] + nums[1] + nums[2] == 0) {
                return {{nums[0], nums[1], nums[2]}};
            }
        }
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue; // Skip duplicates
            int left = i + 1, right = nums.size() - 1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum < 0) {
                    // If the sum is less than zero, we need a larger number, so move the left pointer up
                    left++;
                } else if(sum > 0) {
                    // If the sum is greater than zero, we need a smaller number, so move the right pointer down
                    right--;
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left + 1]) left++; // Skip duplicates
                    while(left < right && nums[right] == nums[right - 1]) right--; // Skip duplicates
                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};
