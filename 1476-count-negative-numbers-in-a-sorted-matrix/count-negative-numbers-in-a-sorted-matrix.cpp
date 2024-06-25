class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // Brute force
        // T.C: O(m*n)
        // S.C: O(1)

        int m = grid.size();
        int n = grid[0].size();
        int negCnt = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] < 0) {
                    negCnt++;
                }
            }
        }

        return negCnt;
    }
};