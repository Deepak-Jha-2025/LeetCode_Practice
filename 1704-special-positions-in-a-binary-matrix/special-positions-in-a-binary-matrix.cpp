class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        // Better solution (Editorial Approach 2)
        // T.C: O(2mn)
        // T.C: O(m+n)

        int m = mat.size();
        int n = mat[0].size();

        vector<int> rowOnesCount(m, 0);
        vector<int> colOnesCount(n, 0);

        // pre-compute the freq of 1s in each row and col simultaneously (O(mn))
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 1) {
                    // Counting can be done simultaneously
                    rowOnesCount[i]++;
                    colOnesCount[j]++;
                }
            }
        }

        // Now, just count the special pos (i,j) satisfying all 3 conditions
        int specialPos = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 1 && rowOnesCount[i] == 1 && colOnesCount[j] == 1) {
                    specialPos++;
                }
            }
        }

        return specialPos;
    }
};