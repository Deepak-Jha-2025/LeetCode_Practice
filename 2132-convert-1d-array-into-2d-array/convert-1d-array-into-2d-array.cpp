class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // Straight forward implementation based
        // T.C: O(m*n)
        // S.C: O(m*n) to return the ans


        vector<vector<int>> ans(m, vector<int>(n));

        if(original.size() != m*n) {
            return {};
        }

        // The situation is similar to row-major mapping (refer notes)
        // row-major mapping is how a 2d array is mapped into a 1d array in the memory
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                ans[i][j] = original[j + n*i];
            }
        }

        return ans;
    }
};