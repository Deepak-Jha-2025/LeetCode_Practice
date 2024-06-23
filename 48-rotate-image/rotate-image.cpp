class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Optimal Solution
        // T.C: 
        // S.C: 

        int n = matrix.size();

        // Step 1: Take transpose
        // O(N*(N-1)/2)
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse every row
        // O(N * N/2)
        for(int i=0; i<n; i++) {
            // Every row is a vector in itself, i.e. matrix[i] is a vector
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};