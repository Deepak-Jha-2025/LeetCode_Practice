class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int a = 1;

        int top = 0, bottom = n-1;
        int left = 0, right = n-1;
        vector<vector<int>> matrix(n, vector<int>(n));

        while(top <= bottom && left <= right) {

            // Pattern: right
            // Direction of traversal: right
            for(int j=left; j<=right; j++) {
                matrix[top][j] = a;
                a++;
            }
            top++;

            // Pattern: right -> bottom
            // Direction of traversal: bottom
            for(int i=top; i<=bottom; i++) {
                matrix[i][right] = a;
                a++;
            }
            right--;

            // The edge case of a single row left/single col left/no ele left arise only if n != m
            // i.e. for rect matrices, so here no further 2 if() checks like in "spiral matrix I" ques

            // Pattern: right -> bottom -> left
            // Direction of traversal: left
            for(int j=right; j>=left; j--) {
                matrix[bottom][j] = a;
                a++;
            }
            bottom--;

            // Pattern: right -> bottom -> left -> top
            // Direction of traversal: top
            for(int i=bottom; i>=top; i--) {
                matrix[i][left] = a;
                a++;
            }
            left++;

        }

        return matrix;
    }
};