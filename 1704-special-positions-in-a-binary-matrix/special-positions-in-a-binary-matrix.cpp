class Solution {
public:
    int countInRows(vector<vector<int>>& mat, int row) {

        int n = mat[row].size();
        int onesCnt = 0;
        int colIdx = 0;

        for(int j=0; j<n; j++) {
            if(mat[row][j] == 1) {
                colIdx = j;
                onesCnt++;
            }
        }

        if(onesCnt == 1) {
            return colIdx;
        }

        return -1;
    }

    int countInCols(vector<vector<int>>& mat, int col) {

        int m = mat.size();
        int onesCnt = 0;

        for(int i=0; i<m; i++) {
            if(mat[i][col] == 1) {
                onesCnt++;
            }
        }

        return onesCnt;
    }

    int numSpecial(vector<vector<int>>& mat) {
        // Optimal solution (just like the optimal for lucky numbers problem)

        // T.C: O(m*(n + m)) 
        // S.c: O(1)

        int m = mat.size();
        int n = mat[0].size();

        int specialPos = 0;
        for(int i=0; i<m; i++) { // O(m*(n + m))
            
            int colIdx = countInRows(mat, i); // O(n) for each row
            if(colIdx >= 0) {
                // there exists a row with a single 1s in it
                // so (i, j) can be potentially a special pos, provided j satisfies the rule too

                if(countInCols(mat, colIdx) == 1) { // O(m) for each col
                    specialPos++;
                }
            }
        }

        return specialPos;
    }
};