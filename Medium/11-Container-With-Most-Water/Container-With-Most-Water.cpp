class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxWater = 0;
        //Strategy is to to have 2 pointers left and right
        //Find the water between them and then move the shortest height
        while(left < right) {
            //Find water stored between current container formed by left and right pointers
            int water = (right - left) * min(height[left],height[right]);
            //Is it max water seen so far
            maxWater = max(maxWater, water);
            //Move the shortest height
            if(height[left] < height[right]) left++;
            else right--;
        }
        return maxWater;
    }
};