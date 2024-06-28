class Solution {
public:
    int findRowMin(vector<vector<int>>& matrix, int row) {
        
        int n = matrix[row].size();
        int mini = matrix[row][0];
        
        for(int j=1; j<n; j++) {
            mini = min(mini, matrix[row][j]);
        }
        return mini;
    }

    int findColMax(vector<vector<int>>& matrix, int col) {

        int m = matrix.size();
        int maxi = matrix[0][col];

        for(int i=1; i<m; i++) {
            maxi = max(maxi, matrix[i][col]);
        }
        return maxi;
    }

    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        // Brute force (simply check for every element, whether it
        // satisfies the given min-max constraints, by everytime 
        // finding the min and max of each row and col)) ==> T.C: O((m*n)^2)

        // Better Solution (using hashtables to keep track of min for each row and max for each col)
        // T.C: O(3mn)
        // S.C: O(m+n)

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> row_minValues(m); // to store the minimum val of each row 
        vector<int> col_maxValues(n); // to store the maximum val of each col 

        // Row minimums O(m*n)
        for(int i=0; i<m; i++) {
            row_minValues[i] = findRowMin(matrix, i);
        }

        // Col maximums O(m*n)
        for(int j=0; j<n; j++) {
            col_maxValues[j] = findColMax(matrix, j);
        }

        // Find lucky no.s (should be present in both the arrays)
        vector<int> luckyNums;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                
                if(matrix[i][j] == row_minValues[i] && matrix[i][j] == col_maxValues[j]) {
                    luckyNums.push_back(matrix[i][j]);
                }
            }
        }

        return luckyNums;
    }
};