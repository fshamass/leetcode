class Solution {
public:
    //Since the requirement is to find the minimum number of overlapping intervals, we need to sort the intervals
    // by their end points. the reason is, if multiple intervals share the same end point, they will all be next to
    // each other and it will be easy to lump all intervals together. 
    // The algorithm works by maintaining the end of previous overlapping intervals so far, and only if the currently 
    // processed interval start point is beyond the end of previous overlapping interval, we will know the overlapping is over.

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int overlaps = 0;
        // Start by sorting the intervals based on their end points
        sort(intervals.begin(),intervals.end(),[](vector<int>& first, vector<int>& second) {return (first[1] < second[1]);});
        // Assume the end of the first interval is the end of previous overlapping intervals
        int right = intervals[0][1];
        // Iterate through the intervals starting from the second one
        for(int i=1;i<intervals.size();i++) {
            // If the start of the current interval is beyond the end of previous overlapping intervals
            if(intervals[i][0] >= right) {
                // Then the overlapping is over, we can update the end of previous overlapping intervals
                right = intervals[i][1];
            } else {
                // Other wise, we have an overlap so increment the count of overlaps
                overlaps++;
            }
        }
        return overlaps;
    }
};