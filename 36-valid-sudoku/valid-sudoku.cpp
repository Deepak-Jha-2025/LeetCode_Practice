class Solution {
public:
    bool checkSubBox(vector<vector<char>>& board, int top, int bottom, int left, int right) {
        
        unordered_set<char> boxChar;
        for(int r=top; r<=bottom; r++) {
            for(int c=left; c<=right; c++) {
                if(board[r][c] != '.') {
                    if(boxChar.find(board[r][c]) != boxChar.end()) {
                        return false; // sub-box is invalid
                    }
                    boxChar.insert(board[r][c]);
                }
            }
        }
        return true; // sub-box is valid
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // Improved Brute/Better --> using bitmask or set data structure
        // T.C: O(2*n^2) + O(2*(n/3)^2) ==> O(n^2)
        // S.C: O(n) + O(n) + O((n/3)^2) => O(n^2)

        // n = 9
        int n = board.size();

        // Here, we can't rely on filling the entire set 1st, then checking if 
        // its size == n or not, b/z the board may be unfilled, so there may not
        // be n elements in a row/col in the 1st place, but it can still be valid
        // if there is not repition, similarly for any sub-box also


        // Checking for rows (1st rule)
        for(int i=0; i<n; i++) { // O(n^2)

            unordered_set<char> rowChar;
            for(int j=0; j<n; j++) {
                if(board[i][j] != '.') {
                    if(rowChar.find(board[i][j]) != rowChar.end()) {
                        return false;
                    }
                    rowChar.insert(board[i][j]);
                }
            }
        }

        // Checking for cols (2nd rule)
        for(int j=0; j<n; j++) { // O(n^2)

            unordered_set<char> colChar;
            for(int i=0; i<n; i++) {
                if(board[i][j] != '.') {
                    if(colChar.find(board[i][j]) != colChar.end()) {
                        return false;
                    }
                    colChar.insert(board[i][j]);
                }
            }
        }

        // Checking for sub-boxes (3rd rule)

        for(int i=0; i<n/3; i++) { // O((n/3)^2) {for the nested loops} * O((n/3)^2) {for the check func}
            
            int top = 3*i;
            int bottom = (n/3)*(i+1) - 1;
            
            for(int j=0; j<n/3; j++) {
            
                int left = 3*j;
                int right = (n/3)*(j+1) - 1;

                // Any grid/sub-box has 4 sides, so it needs 4 ptrs (just like subarr needs 2 ptrs)
                // So, a sub-box is defined b/w top and bottom, left and right

                if(checkSubBox(board, top, bottom, left, right) == false) {
                    return false; // grid is invalid so sudoku is invalid
                }
            }
        }

        return true;

    }
};