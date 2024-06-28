class Solution {
public:
    int findRowMin(vector<vector<int>>& matrix, int& minVal, int row) {
        
        minVal = matrix[row][0];
        int n = matrix[row].size();

        int minCol_idx = 0;
        for(int j=1; j<n; j++) {
            if(matrix[row][j] < minVal) {
                minVal = matrix[row][j];
                minCol_idx = j;
            }
        }

        return minCol_idx;
    }

    int findColMax(vector<vector<int>>& matrix, int col) {

        int maxVal = matrix[0][col];
        int m = matrix.size();

        for(int i=1; i<m; i++) {
            maxVal = max(maxVal, matrix[i][col]);
        }

        return maxVal;
    }

    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        // Optimal solution (in-place)

        // Intuition: Only check for those numbers which validate the 1st criteria, i.e. min in their row
        // b/z only those potentially may/may not be lucky numbers (provided they validate the 2nd criteria
        // also, that they are the max in their col as well)

        // T.C: O(m*(n+m))
        // S.C: O(1)

        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> luckyNums;
        for(int i=0; i<m; i++) {  // O(m*(n+m))

            // 1st find min val in row
            int minVal = 0;
            int minCol_idx = findRowMin(matrix, minVal, i); // O(n)

            // now, in whatever col idx is that row min value, check if that same min val is
            // the max val in that col as well, if yes, it is lucky, else discard the entire row
            // (b/z rest of the no.s of the row aren't even potential candidates to be lucky no.s
            //  as they failed the 1st criteria itself, so no use checking the 2nd for them)

            int maxVal = findColMax(matrix, minCol_idx); // o(m)
            if(minVal == maxVal) {
                luckyNums.push_back(minVal);
                // luckyNums.push_back(maxVal);
            }
        }

        return luckyNums;
    }
};