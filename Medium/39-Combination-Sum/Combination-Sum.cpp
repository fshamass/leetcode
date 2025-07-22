class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Straightforward depth first search approach to find explore all combinations
        // The advantage of sorting the array is, if current sum is greater than target,
        // we don't need to continue because we know the sum will only get greater for subsequent elements
        sort(candidates.begin(), candidates.end());
        // Combination is a dynamic vector that we push elements to it when entering new level
        // and we pop element when we return from a level. it keeps track of what elements we are
        // currently working with in each level
        vector<int> combinations;
        vector<vector<int>> results;
        dfs(candidates, combinations, results, target, 0, 0);
        return results;
    }
private:
    void dfs(vector<int>& candidates, vector<int>& combinations, vector<vector<int>>& results, int target, int sum, int start) {
        if(sum == target) {
            results.push_back(combinations);
            return;
        }
        // we are already over target sum, no need to explore any further, subsequent elements will only increase the sum
        if(sum > target) return;
        // Start from the beging element in current level
        for(int i=start;i<candidates.size();i++) {
            // Add current element to the dynamic combination to explore it
            combinations.push_back(candidates[i]);
            // Go to next level after adding current element to sum from previous level
            dfs(candidates, combinations, results, target, sum + candidates[i], i);
            combinations.pop_back();
        }
    }
};