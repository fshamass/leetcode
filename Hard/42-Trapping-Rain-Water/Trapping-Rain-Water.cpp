class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() -1;
        int maxLeft = 0;
        int maxRight = 0;
        int water = 0;
        while(left < right) {
            //Work on shortest height
            if(height[left] < height[right]) {
                // If this height is higher than any height seen so far, update max height
                if(height[left] > maxLeft) {
                    maxLeft = height[left];
                } else {
                    // Icrement the water trapped between this hight and the lax height so far
                    water += maxLeft - height[left];
                }
                left++;
            }else {
                if(height[right] > maxRight) {
                    maxRight = height[right];
                } else {
                    water += maxRight - height[right];
                }    
                right--;
            }
        }
        return water;
    }
};
