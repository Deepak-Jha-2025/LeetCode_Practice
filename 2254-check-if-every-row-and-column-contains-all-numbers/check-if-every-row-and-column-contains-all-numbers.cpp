class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        // Better Sol/Optimized Brute - using set data structure

        // This is the optimal solution b/z xor optimization fails for this ques

        // T.C: O(n*2n) + O(n*2n)
        // S.C: O(n)

        int n = matrix.size();
        unordered_set<int> s;

        // Checking along all rows --> O(n*(2n))
        for (int i = 0; i < n; i++) {
            // O(n) * O(1), for best n avg case of set
            for (int j = 0; j < n; j++) {
                s.insert(matrix[i][j]); // would store all unique ele of a row
            }

            // Now, as all unique ele were stored in the set for a row
            // So, if no ele from 1 to n is missing, then it means size of set
            // must be n vice versa also true

            // O(1)
            if (s.size() != n) {
                return false;
            }

            // O(n), n = size of set = n in worst case if all elements in row
            // are unique (from 1 to n)
            s.clear(); // Check for this row done, so empty the set to use it
                       // for next row
        }

        // Checking along all cols --> O(n*(2n))
        for (int j = 0; j < n; j++) {
            // O(n) * O(1), for best n avg case of set
            for (int i = 0; i < n; i++) {
                s.insert(matrix[i][j]); // would store all unique ele of a row
            }

            // Now, as all unique ele were stored in the set for a row
            // So, if no ele from 1 to n is missing, then it means size of set
            // must be n vice versa also true

            // O(1)
            if (s.size() != n) {
                return false;
            }

            // O(n), n = size of set = n in worst case if all elements in row
            // are unique (from 1 to n)
            s.clear(); // Check for this row done, so empty the set to use it
                       // for next row
        }

        return true;
    }
};