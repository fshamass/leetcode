class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 0;
        // Vector to stores candies - give all children 1 candy initially
        vector<int> candies(ratings.size(),1);
        // First pass, focus on rating to left of current child
        for(int i=1;i<ratings.size();i++) {
            if(ratings[i] > ratings[i-1]) candies[i] = candies[i-1] + 1;
        }
        // Second pass, focus on rating to right of current child
        // if rating of current child is greater than rating of child to the right
        for(int i=ratings.size()-2;i>=0;i--) {
            // do not assign current child candies, use max to not overwrite the first pass criteria
            if(ratings[i] > ratings[i+1]) candies[i] = max(candies[i],candies[i+1]+1);
        }
        //Total candies will be the sum of candies for all children
        for(const auto& candy:candies) {
            sum += candy;
        }
        return sum;
    }
};
