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

        // Better Solution (using sets to keep track of min for each row and max for each col)
        // T.C: O(3mn)
        // S.C: O(m+n)

        int m = matrix.size();
        int n = matrix[0].size();

        unordered_set<int> row_minValues; // to store the minimum val of each row 
        unordered_set<int> col_maxValues; // to store the maximum val of each col 

        // Row minimums O(m*n)
        for(int i=0; i<m; i++) {
            row_minValues.insert(findRowMin(matrix, i));
        }

        // Col maximums O(m*n)
        for(int j=0; j<n; j++) {
            col_maxValues.insert(findColMax(matrix, j));
        }

        // Now that we are using sets, so no need to iterate in matrix again (O(m*n)) 
        // or no need to linear search every value of one array in the other (O(m*n))

        // As unordered_set takes O(1) time in avg and best case to search, so using .find() 
        // function in any of the 2 sets (either the size m set or the size n set) would take
        // O(m) or O(n) time

        // Find lucky no.s (should be present in both the sets)
        vector<int> luckyNums;
        unordered_set<int>::iterator it;
        for(it = row_minValues.begin(); it != row_minValues.end(); it++) {
            if(col_maxValues.find(*it) != col_maxValues.end()) {
                luckyNums.push_back(*it);
            }
        }

        return luckyNums;
    }
};