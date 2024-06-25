class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // Optimal 
        // T.C: O(m+n) in worst case, O(m) or O(n) in best case
        // s.C: O(1)

        // start from top right(for row wise traversal) or bottom left(for col wise traversal)
        // To understand why to start from there and also the time(dry run 3 test cases, one is
        // the example 1 from the ques itself, and the other 2 cases of all +ves and all -ves)

        // Idea is that it's sorted from left to right in decreasing order 
        // so right to left it'll increase, so if a +ve found in the row iterating R to L
        // that means uske piche ke saare bhi saare +ve hi honge surely, so skip that row

        // Similarly for col, it is sorted in decreasing order from top to bottom, so while
        // iterating from top to bottom, if a -ve is found, that means kyuki niche ki taraf
        // values ghat rahi hain, aur abhi -ve mila hain, toh iske niche wale +ve thode honge, 
        // -ve hi honge woh bhi, to remaining col from current index is the count, move to next col

        int m = grid.size();
        int n = grid[0].size();

        int negCnt = 0;
        int row = 0;   // to keep track of row no.
        int col = n-1; // to keep track of col no.

        while(row < m && col >= 0) {

            if(grid[row][col] < 0) {
                // entire remaining col will also be -ves only, so count directly from idx
                // assume hypothetically, before row idx, only +ves were there, and row is 
                // the idx, where the 1st -ve of the col has occured, so row = no. of +ves so
                // far in the jth col, so:
                // no. of -ves = column size - row = m - row

                negCnt += (m - row);
                col--; // row is still fixed
            }
            else {
                // all elements before this in prev cols will also be +ve 
                // so no need to further check in this row and move to next row

                row++; // col is still fixed
            }
        }

        return negCnt;
    }
};