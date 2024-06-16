class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        for(int i=0; i<m; i++) {

            int n = matrix[i].size();
            for(int j=0; j<n; j++) {
                int r = i;
                int c = j;

                while(r<m-1 && c<n-1) {
                    if(matrix[r][c] != matrix[r+1][c+1]) {
                        return false;
                    }
                    r++, c++;
                }
            }
        }

        return true;
    }
};