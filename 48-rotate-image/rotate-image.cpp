class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Brute Force
        // T.C: O(n^2)
        // S.C: O(n^2)

        // Create an ext matrix to store each element in its desired place 
        // and return the ans
        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int>(n));    // n x n matrix created, uninitialized
        // vector<vector<int>> ans(n, vector<int>(n, 0)); // n x n matrix created, initialized with 0

        // Iterate the matrix and map the elements
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                ans[j][(n-1)-i] = matrix[i][j];
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                matrix[i][j] = ans[i][j];
            }
        }

        // matrix = ans; // shortcut for above nested loops
    }
};