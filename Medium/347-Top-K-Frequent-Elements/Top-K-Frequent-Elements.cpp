class Solution {
public:
    //Algorithm for this problem is straight forward. We can use a hash table to keep track of frequencies 
    // of each element. However, the challenge is to get the k most frequent elements efficiently.
    // One way is to use a max heap (priority queue) to keep track of the k most frequent elements.
    // Looping through the hash table to find is not efficient since it will take O(n) time.
    // Using a max heap will take O(n log k) time since we will be pushing and popping from the heap
    // at most k times for each of the n elements in the hash table.
    // A very efficient way is to use a deque to keep track of the k most frequent elements. 
    // The idea is to maintain the deque in decreasing order of frequencies.
    // That is, the front of deque will always have the most frequent element while traversing the nums array
    // So that at the end of the traversal, we can simply pop the first k elements from the front of the deque

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        deque<int> dq;
        vector<int> mostFreq;
        if(nums.size() == k) return nums;

        for(auto& num:nums) {
            // Increment frequency of the number in hash table
            freq[num]++;
            // Pop all elements from back of the deque that are less frequent than current number
            while((!dq.empty()) && (dq.back() < freq[num])) {
                dq.pop_back();
            }
            // Push the current number frequency to the back of the deque
            dq.push_back(freq[num]);
        }
        // Pop the first k elements from the front of the deque to solution
        while(mostFreq.size() < k) {
            mostFreq.push_back(deq.front());
            deq.pop_front();
        }
        return mostFreq;
    }
};