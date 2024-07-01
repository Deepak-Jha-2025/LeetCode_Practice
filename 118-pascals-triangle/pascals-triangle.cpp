class Solution {
public:
    vector<int> generateRow(int rowIdx) {
        vector<int> row;
        long long ans = 1; // for 0th col
        row.push_back(ans);

        for(int colIdx = 1; colIdx <= rowIdx; colIdx++) {
            ans = ans * (rowIdx - (colIdx - 1));
            ans = ans / colIdx;
            row.push_back(ans);
        }

        return row;
    }

    vector<vector<int>> generate(int numRows) {
        // Optimal Solution:
        // T.C: O(n^2) , n = numRows (1-based idx)
        // S.C: O(1)

        vector<vector<int>> ans;

        for(int row=0; row < numRows; row++) {
            ans.push_back(generateRow(row));
        }

        return ans;
    }
};