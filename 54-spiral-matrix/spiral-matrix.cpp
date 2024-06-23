class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Only solution => Optimal
        // T.C: O(m*n)
        // S.c: O(m*n) --> just to return the answer

        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0, right = n - 1;
        int top = 0, bottom = m - 1;
        vector<int> ans;

        while (top <= bottom && left <= right) {

            // Traversal Direction: right
            // Pattern: right
            for (int j = left; j <= right; j++) {
                ans.push_back(matrix[top][j]);
            }
            top++;

            // Traversal Direction: bottom
            // Pattern: right -> bottom
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            // Traversal Direction: left
            // Pattern: right -> bottom -> left
            if (top <= bottom) // To cover the edge case of single row or no
                               // more elements key hint: all 4 ptrs must be
                               // checked for each pattern traversal
            {
                for (int j = right; j >= left; j--) {
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            // Traversal Direction: top
            // Pattern: right -> bottom -> left -> top
            if (left <= right) // To cover the edge case of a single column or
                               // no elements
            {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};