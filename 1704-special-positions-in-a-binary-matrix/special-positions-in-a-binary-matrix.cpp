class Solution {
public:
    bool checkRow(vector<vector<int>>& mat, int row) {
        
        int n = mat[row].size();
        int oneCount = 0;
        for(int j=0; j<n; j++) {
            if(mat[row][j] == 1) {
                oneCount++;
            }
        }

        return (oneCount == 1); // validates row conditions, all others in its row are 0
    }

    bool checkCol(vector<vector<int>>& mat, int col) {
        
        int m = mat.size();
        int oneCount = 0;
        for(int i=0; i<m; i++) {
            if(mat[i][col] == 1) {
                oneCount++;
            }
        }

        return (oneCount == 1); // validates row conditions, all others in its row are 0
    }

    int numSpecial(vector<vector<int>>& mat) {
        // Brute force
        // T.C: O(m*n*(m+n))
        // S.C: O(1)

        int m = mat.size();
        int n = mat[0].size();

        int specialPos = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {

                if(mat[i][j] == 1) {
                    // criteria 1st fulfilled, potential possible special pos
                    if(checkRow(mat, i) && checkCol(mat, j)) {
                        specialPos++;
                    }
                }
            }
        }

        return specialPos;
    }
};