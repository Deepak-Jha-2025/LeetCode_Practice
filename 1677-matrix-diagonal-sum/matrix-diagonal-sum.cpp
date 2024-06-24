class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        // Straight away implementation based
        // Only one solution => Optimal solution

        int n = mat.size();
        int diagSum = 0;
        for(int i=0; i<n; i++) {
            diagSum += mat[i][i];

            if(i != ((n-1)-i)) {
                diagSum += mat[i][n-1-i];
            }
        }

        return diagSum;
    }
};