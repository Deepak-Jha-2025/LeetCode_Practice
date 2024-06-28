class Solution {
public:
    int countRowOnes(vector<vector<int>>& mat, int& rowOnesCount, int row) {

        int colIdx = 0;
        int n = mat[row].size();
        for(int j=0; j<n; j++) {
            if(mat[row][j] == 1) {
                colIdx = j;
                rowOnesCount++;
            }
        }
        return colIdx;
    }

    int countColOnes(vector<vector<int>>& mat, int col) {

        int cnt = 0;
        int m = mat.size();
        for(int i=0; i<m; i++) {
            if(mat[i][col] == 1) {
                cnt++;
            }
        }
        return cnt;
    }

    int numSpecial(vector<vector<int>>& mat) {
        // Better solutin (uses hash tables for rows/cols)
        // Similar to approach 2 or editorial (just a bit diff. version)

        // T.C: O(m*n) + O(m*m) = O(m*(n+m))
        // S.C: O(m)

        int m = mat.size();
        int n = mat[0].size();

        // Just for row is enough, this would 1st check if the row i has only a single 1 or not
        // If it does, then the col j of that 1, will be stored in this hash table, as the pos(i,j)
        // can potentially be a special position only if the col j also has just a single 1, which 
        // we will check after filling the row vector.
        vector<int> row(m);

        int specialPos = 0;
        for(int i=0; i<m; i++) {
            
            int rowOnesCount = 0;
            int j = countRowOnes(mat, rowOnesCount, i); // j = col where the single '1' of the row is present
            if(rowOnesCount == 1) {
                // mat[i][j] == 1 (validated)
                // all other elements in ith row = 0 (validated)
                // So, (i, j) is a potential special postition (it may or may not be), 
                // depends on the col (if all other elements in jth col = 0 <==> oneCount == 1
                // for that col also)
                
                if(countColOnes(mat, j) == 1) {
                    // i, j == special position
                    specialPos++;
                }
            }
        }

        return specialPos;
    }
};