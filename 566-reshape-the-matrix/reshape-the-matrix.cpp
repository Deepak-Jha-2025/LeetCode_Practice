class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();

        if(r*c != m*n) {
            return mat;
        }

        vector<vector<int>> reshape(r, vector<int>(c));

        // mat ptrs: mi, mj
        // reshape ptr: ri, rj

        int mi = 0, mj = 0;
        int ri = 0, rj = 0;

        for(mi = 0; mi < m; mi++) {
            
            for(mj = 0; mj < n; mj++) {

                if(ri < r && rj < c) {
                    reshape[ri][rj] = mat[mi][mj];
                    rj++;        
                }

                if(rj == c) {
                    // that row ri in reshape is finished, move to next row
                    ri++;
                    rj = 0;
                }
            }
        }

        return reshape;
    }
};