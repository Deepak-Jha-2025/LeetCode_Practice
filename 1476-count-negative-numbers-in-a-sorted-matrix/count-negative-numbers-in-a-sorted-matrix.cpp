class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // Somewhat optimized brute/improved Brute
        // T.C: O(n*m)
        // S.C: O(1)

        int m = grid.size();
        int n = grid[0].size();
        
        // sorted in decreasing order
        // negatives are found/concentrated towards right and bottom portion
        // so start looking from there and stop when a positive found, b/z 
        // after that only +ves will be there, so no use iterating for that row

        int negCnt = 0;
        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                if(grid[i][j] < 0) {
                    negCnt++;
                }

                if(grid[i][j] > 0) {
                    continue;
                }
            }
        }

        return negCnt;
    }
};