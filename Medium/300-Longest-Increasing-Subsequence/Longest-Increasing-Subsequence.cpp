
// Strategy: Use a dynamic programming approach with binary search to find the length of 
//the longest increasing subsequence.
// We use a vector `tail` and for every element in input vector (nums), we find the first element 
// in tail vector from left that is greater than input element. if such element exists, then
// we replace that element with the current input element, otherwise we append the current input
// element to the tail vector.
// Why first element in tail from left that is greater than current input element?
// Because we want to keep the tail vector sorted in increasing order, so that we can always
// find the next element that is greater than current input element in tail vector.
// There are two ways to do this, either by utilizing c++ std library function, lower_bound
// or by implementing our own binary search. 
// This is the solution we will use c++ std library function

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tail;
        for(auto& num:nums) {
            auto itr = lower_bound(tail.begin(), tail.end(),num);
            if(itr == tail.end()) {
                tail.push_back(num);
            } else {
                *itr = num;
            }
        }
        return tail.size();
    }
};

// If lower_bound is not available, we can implement our own binary search
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tail;
        //Push 1st element to tail vector to have at least one element to start with
        // but make sure the input vector is not empty
        if(nums.empty()) return 0;
        tail.push_back(nums[0]);
        // Start from the second element in input vector
        for(int i=1;i<nums.size();i++) {
            // Do binary search to find the element in tail
            auto [left, right] = binarySearch(tail,nums[i]);
            // If current input element exist in tail vector, we will replace it with 
            // current input element
            if(left == right) {
                tail[left] = nums[i];
            } else if (left >= tail.size()) {
                // if binary search returns left index outside of tail vector, that means 
                // current input element is greater than all elements in tail vector. 
                // Just push it to the end
                tail.push_back(nums[i]);
            } else {
                // Otherwise, the left index will be the first element in tail vector that 
                // is greater than current input element
                tail[left] = nums[i];
            }
        }
        return tail.size();
        
    }

    pair<int,int> binarySearch(vector<int>& vec, int target) {
        int left = 0;
        int right = vec.size() - 1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            if(target == vec[mid]) {
                return {mid,mid};
            } else if(target > vec[mid]) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return {left,right};
    }
};