class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        // Straight away implementation based
        // Only one solution => Optimal solution
        // T.C: O(n)
        // S.C: O(1)

        int n = mat.size();
        int diagSum = 0;
        for(int i=0; i<n; i++) {
            diagSum += (mat[i][i] + mat[i][n-1-i]);

            if(i == (n-1-i)) {
                // Same sum of centre ele(common to both diagonals) has been added twice
                // so remove once (to compensate that extra addition)

                // diagSum -= mat[i][n-1-i];
                diagSum -= mat[i][i];
            }
        }

        return diagSum;
    }
};