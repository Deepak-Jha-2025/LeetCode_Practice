class Solution {
public:
    long long nCr(int n, int r) {
        long long res = 1;
        for(int i=0; i<r; i++) {
            res = res * (n-i);
            res = res / (i+1);
        }
        return res;
    }

    vector<int> getRow(int rowIndex) {
        // Brute Force
        // T.C:
        // S.C: O(1)

        // No. of elements in a row = rowIndex(0-based) + 1
        int n = rowIndex + 1;
        vector<int> row(n, 0);

        for(int colIndex=0; colIndex < n; colIndex++) 
        {
            row[colIndex] = nCr(rowIndex, colIndex);
        }

        return row;
    }
};