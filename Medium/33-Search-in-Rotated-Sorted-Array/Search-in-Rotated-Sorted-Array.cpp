class Solution {
public:
    int search(vector<int>& nums, int target) {
        //The strategy is to find the pivot point where the array is rotated and then perform binary search in the appropriate half.
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            // Determine which side is properly sorted
            if(nums[left] <= nums[mid]) { // Left side is sorted
                if(target >= nums[left] && target < nums[mid]) {
                    right = mid - 1; // Target is in the left half
                } else {
                    left = mid + 1; // Target is in the right half
                }
            } else { // Right side is sorted
                if(target > nums[mid] && target <= nums[right]) {
                    left = mid + 1; // Target is in the right half
                } else {
                    right = mid - 1; // Target is in the left half
                }
            }
        }
        return -1; // Target not found  
    }
};