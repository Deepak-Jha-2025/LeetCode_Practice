class Solution {
public:
    int findMaxElement(vector<int> v) {
        int maxi = v[0];
        for(int i=1; i<v.size(); i++) {
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }

    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        // Brute Force (same as editorial approach)
        // T.C: O(3n^2)
        // S.C: O(2n)

        // Step 1: find max element of each row and column as these max height
        // buildings are the ones deciding the skyline, 

        // We'll store the max of all rows in a rowSkyline array (this is skyline for both east and west, 
        // so 1 array is enough no need to make 2 separate arrays for 2 separate directions)

        // Similarly, store the max of all cols in a colSkyline array (this is skyline for both north and south, 
        // so 1 array is enough no need to make 2 separate arrays for 2 separate directions)

        int n = grid.size();
        vector<int> rowSkyline(n, 0);
        vector<int> colSkyline(n, 0);

        // find max along rows => O(n^2)
        for(int i=0; i<n; i++) { 
            rowSkyline[i] = findMaxElement(grid[i]);
        }

        // find max along cols => O(n^2)
        for(int j=0; j<n; j++) {
            
            int maxi = grid[0][j];
            for(int i=1; i<n; i++) {
                maxi = max(maxi, grid[i][j]);
            }

            colSkyline[j] = maxi;
        }


        // Step 2: Traverse the matrix again, and for each element check the following:

        /* 1. if that element is in either one of the 2 arrays, it means it is the maximum
              height building for either a row or col (any 2 directions) and is affecting the
              skyline, so changing it would change the skyline, which is not allowed, so leave it.

           2. if that element is in neither of the rows, so it means that building is not affecting
              the skyline, so we can change it. 

              *** Now, change it to min(rowSkyline[i], colSkyline[j]) b/z in this way, both the skylines
                  remain unaffected, if we change it to the maximum of the 2, the minumum value will have
                  to adjust, thus changing the skyline, (Dry run the given test case) to understand.
        */

        int maxSum = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {

                if(grid[i][j] != rowSkyline[i] && grid[i][j] != colSkyline[j]) 
                {
                    maxSum += (min(rowSkyline[i], colSkyline[j]) - grid[i][j]);

                    grid[i][j] = min(rowSkyline[i], colSkyline[j]);
                }
            }
        }

        return maxSum;
    }
};