class Solution {
public:
    // Intervals overlap if the start of one interval is less than or equal to the end of the previous interval.
    // However, this condition is true only if the intervals are sorted by their start times.
    // So we will sort the intervals by their start times and then iterate through them to merge overlapping intervals.
    // If two intervals overlap, now we have new interval starts with start of the first interval and ends with the 
    // maximum end of both intervals.
    // Further more, this new interval might overlap with the next interval, so to keep track of all the overlapping 
    // intervals we need to maintain start and end of the currently merged interval.
    // The way we this is by maintaining two variables, min and max, that will keep track of the start and end of all 
    // current merged intervals until we see interval that start beyond the end of current merged interval end (max variable).
    // In this case, we will push the current merged inteval to the result vector and update min and max to the start and end
    // of the next interval
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        // Sort intrvals by their start times
        sort(intervals.begin(),intervals.end(), [](vector<int>& first, vector<int>& second) {return first[0] < second[0];});
        // Set the initial min and max to the start and end of the first interval
        int min = intervals[0][0];
        int max = intervals[0][1]; 
        // Loop through the intervals starting from the second interval
        for(int i=1;i<intervals.size();i++) {
            // Condition for overlapped interval, update max
            if(intervals[i][0] <= max) {
                // end of new interval is grester than current max, so we update max
                if(intervals[i][1] > max) {
                    max = intervals[i][1];
                }
            } else {
                // Current interval does not overlap, push the current merged interval to the result
                res.push_back(vector<int>{min,max});
                // Update min and max to the start and end of the next interval
                min = intervals[i][0];
                max = intervals[i][1];
            }
        }
        // After the loop, we need to push the last merged interval to the result
        res.push_back(vector<int>{min,max});
        return res;
    }
};