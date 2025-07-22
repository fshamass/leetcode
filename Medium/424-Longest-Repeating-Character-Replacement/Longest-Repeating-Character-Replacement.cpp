class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.empty()) return 0;
        unordered_map<char,int> freq;
        // Strategy: Use a sliding window approach to find the longest substring with at most k replacements.
        // We will maintain a frequency map to count the occurrences of characters in the current window.
        // The key idea is to keep track of the maximum frequency of any character in the current window.
        // This way, we can find out the least characters we need to replace to make all characters in the window the same.
        int left = 0;
        int maxLen = 0;
        int maxFreq = 0;
        // Window will be defined by left and right pointers
        // We will iterate through the string with right pointer
        for(int right = 0;right<s.length();right++) {
            // Increment the frequency of the current character
            freq[s[right]]++;
            // Update the maximum frequency of character in the current window
            maxFreq = max(maxFreq, freq[s[right]]);
            // At each point we have the number of most common character in the current window captured in maxFreq 
            // so the difference between the size of the current window (right - left + 1) and the maximum frequency 
            // is the number of characters that we can replace to match most frequent character and end up with window 
            // of same characters. However, the flipped characters should not exceed k, so we check that condition
            if(right - left + 1 - maxFreq > k) {
                // If the condition is not satisfied, we need to shrink the window from the left
                // Decrease the frequency of the character at the left pointer
                freq[s[left]--];
                left++;
            }
            // In either case, the max length of repeating character is the size of the current window
            // because we are guaranteed that the number of characters that need to be replaced does not exceed k
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};