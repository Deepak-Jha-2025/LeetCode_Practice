class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Optimal Solution
        // T.C: O(2*n*m)
        // S.C: O(n + m)

        int n = matrix.size(); 
        int m = matrix[0].size();

        // vector<int> col(m, 0); // matrix[0][1...m-1] + col0
        // vector<int> row(n, 0); // matrix[0...n-1][0]

        // Mark the rows/cols of zeros
        int col0 = 1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == 0) {
                    // mark the ith row
                    matrix[i][0] = 0;
                    
                    // mark the jth col
                    if(j != 0) {
                        matrix[0][j] = 0;
                    }
                    else {
                        col0 = 0;
                    }
                }
            }
        }

        // Temprarily our 1st col and row of matrix are like hash/flag arrays, so don't touch 
        // them until their job is completely done. By that I specifically mean the hash col,
        // i.e. the 1st col, whose job is not done until the elements(1 <= i,j < n or m) and
        // the 1st row is converted.
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {

                // conversion possible only if non-zero element is found
                if(matrix[i][j] != 0) {
                    // check for col and row
                    if(matrix[0][j] == 0 || matrix[i][0] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        // 1st row converted (1st column's dependency completely finished)
        if(matrix[0][0] == 0) {
            // for j=0, element is already 0, so start from j=1
            for(int j=1; j<m; j++) {
                matrix[0][j] = 0;
            }
        }

        // Now, finally convert the independent 1st column
        if(col0 == 0) {
            for(int i=0; i<n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};