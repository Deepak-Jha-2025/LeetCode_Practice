class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Better Solution
        // T.C:
        // S.C:

        int n = rowIndex + 1;
        vector<int> row;

        long long ans = 1;
        row.push_back(ans); // for 0th col

        // rowIndex -> 0-based
        // n        -> 1-based
        for(int col = 2; col <= n; col++) {
            ans = ans * (n - (col - 1));
            ans = ans / (col-1);
            row.push_back(ans);
        }

        return row;

    }
};