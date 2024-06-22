class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Better Solution
        // T.C: O(2*n*m)
        // S.C: O(n + m)

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> row(n, 0);
        vector<int> col(m, 0);

        // Mark the rows/cols of zeros
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // Set an element = 0, if it's row/col is marked, i.e.
        // it belongs to the row or column of a 0
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};