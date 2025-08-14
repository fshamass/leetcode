class Solution {
public:
    // In order to insert the interval, we first need to figure out where the interval should be inserted
    // Since the intervals are stated to be non overlapping and sorted, then 
    // there are 3 scenarios that we need to handle:
    // 1. The starting point of the new interval overlap with one of the existing interval
    // 2. The starting point of the new interval does not overlap with any interval but the
    // end point of the new interval overlaps with one of the exist intervals
    // 3. The new interval fits perfectly in between 2 existing intervals. no overlaps in start and end points
    // In all 3 scenarios, to find where the new interval should be inserted is to look for an 
    // existing interval where its end point is greater than or equal to start point of new interval
    // Once we find that interval, then we follow the interval merge algorithm:
    // Create temporary interval with start equal to min of both intervals and end is max of both intervals
    // The problem statement said the intervals are non overlapping but now that we merged the new interval
    // with existing interval, we need to ensure that the temporary interval does not overlap with subsequent 
    // intervals, if so we continue merging existing subsequent intervals with temporary interval
    // Once we get to point where temporary interval does not overlap with subsequent interval, we push the 
    // temporary interval into solution and continue pushing all remaining intervals into solution

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int index = 0;
        int n = intervals.size();
        vector<vector<int>> result;

        // Find where the interval should be inserted, at what index
        while((index < n) && (intervals[index][1] < newInterval[0])) {
            // push intervals into solution as search continue
            result.push_back(intervals[index]);
            index++;
        }
        //create the temporary interval and continue merging subsequent intervals if necessary
        while((index < n) && (intervals[index][0] <= newInterval[1])) {
            newInterval[0] = min(intervals[index][0], newInterval[0]);
            newInterval[1] = max(intervals[index][1], newInterval[1]);
            index++; 
        }
        //Push the new interval into solution
        result.push_back(newInterval);

        //Push all subsequent intervals into solution 
        while(index<n) {
            result.push_back(intervals[index]);
            index++;
        }
        return result;
    }
};