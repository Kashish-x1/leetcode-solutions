class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();          // Get number of rows
    if (n == 0) return;             // Handle edge case of empty matrix
    int m = matrix[0].size();       // Get number of columns
    int col0 = 1;                   // To track if the first column needs to be zeroed

    // First pass to mark zeros in the first row and first column
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // Mark the ith row
                matrix[i][0] = 0;
                // Mark the jth column
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0; // Mark that the first column needs to be zeroed
            }
        }
    }

    // Second pass to set zeros based on the marks
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Zero out the first row if needed
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }

    // Zero out the first column if needed
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }
}  
};