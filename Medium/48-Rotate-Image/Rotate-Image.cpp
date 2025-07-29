class Solution {
public:
    // Strategy: To rotate the matrix by 90 degrees clockwise, we can first transpose the matrix and then reverse each row.
    void rotate(vector<vector<int>>& matrix) {
        // Transpose the matrix by swapping elements across the diagonal
        // This means swapping matrix[i][j] with matrix[j][i]
        for(int i=0;i<matrix.size();i++) {
            for(int j=i+1;j<matrix[i].size();j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        // Reverse each row of the transposed matrix
        for(int i=0;i<matrix.size();i++) {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};