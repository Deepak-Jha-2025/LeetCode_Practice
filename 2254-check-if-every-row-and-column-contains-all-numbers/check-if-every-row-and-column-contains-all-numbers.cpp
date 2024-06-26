class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        // Brute force - using bitmask array
        // T.C: O(n) + O(n*3n) + O(n*3n)
        // S.C: O(n)

        int n = matrix.size();
        vector<int> bitmask(n+1, 0); // O(n)

        // Checking along all rows --> O(n*(3n))
        for(int i=0; i<n; i++) {
            // O(n)
            for(int j=0; j<n; j++) {
                bitmask[matrix[i][j]] = 1; // mark its presence
            }

            // Iterate in the bitmask to see if all elements from 1 to n where present in the row
            // O(n)
            for(int k=1; k<=n; k++) {
                if(bitmask[k] == 0) {
                    return false;
                }
            }

            // Check for current row done, reset the bitmask to use for next row = O(n)
            fill(bitmask.begin(), bitmask.end(), 0); // or simply use loop
        }

        // Checking along all cols --> O(n*(3n))
        for(int j=0; j<n; j++) {
            // O(n)
            for(int i=0; i<n; i++) {
                bitmask[matrix[i][j]] = 1; // mark its presence
            }

            // Iterate in the bitmask to see if all elements from 1 to n where present in the row
            // O(n)
            for(int k=1; k<=n; k++) {
                if(bitmask[k] == 0) {
                    return false;
                }
            }

            // Check for current row done, reset the bitmask to use for next row = O(n)
            fill(bitmask.begin(), bitmask.end(), 0); // or simply use loop
        }

        return true;
    }
};