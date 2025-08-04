class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Strategy: All spiral probmens can be solved using a similar approach.
        // We will traverse the matrix in a spiral order. That is, we will start from the 
        // top-left corner and move right, then down, then left, and finally up.
        // Repeating this process until we have traversed the entire matrix.
        // The key for this traversal scheme is to maintain four boundaries:
        // iMin: the minimum row index (top row) that we have not traversed yet
        // iMax: the maximum row index (bottom row) that we have not traversed yet
        // jMin: the minimum column index (left column) that we have not traversed yet
        // jMax: the maximum column index (right column) that we have not traversed yet
        // Once we traverse row from left to right, we will increment iMin.
        // Once we traverse column from top to bottom, we will decrement jMax.
        // Once we traverse row from right to left, we will decrement iMax.
        // Once we traverse column from bottom to top, we will increment jMin.
        // We will continue this process until iMin > iMax or jMin > jMax.
        vector<int> result;
        int rows = matrix.size();
        int cols = matrix[0].size();
        // Declare the boundaries
        int iMin = 0;
        int iMax = rows-1;
        int jMin = 0;
        int jMax = cols - 1;
        int index = 1;
        // Loop until we have traversed the entire matrix
        while((jMin <= jMax) && (iMin <= iMax)) {
            // Traverse the top row from left to right
            for(int j = jMin;j<=jMax;j++) result.push_back(matrix[iMin][j]);
            iMin++;
            // Traverse the right column from top to bottom
            for(int i = iMin;i<=iMax;i++) result.push_back(matrix[i][jMax]);
            jMax--;
            // Traverse the bottom row from right to left only if we still have rows left
            if(iMin<=iMax) {
                for(int j = jMax;j>=jMin;j--) result.push_back(matrix[iMax][j]);
                iMax--;
            }
            // Traverse the left column from bottom to top only if we still have columns left
            if(jMin <= jMax) {
                for(int i = iMax;i>=iMin;i--) result.push_back(matrix[i][jMin]);
                jMin++;
            }
        }
        return result;
    }
};