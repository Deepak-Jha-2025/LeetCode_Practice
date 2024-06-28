class Solution {
public:
    string checkBoard(vector<vector<int>>& board) {

        // check if there are three of the same (non-empty) character filling any row
        for (int i = 0; i < 3; i++) {

            if(board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') return "A";
            if(board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O') return "B";
        }

        // check if there are three of the same (non-empty) character filling any col
        for (int j = 0; j < 3; j++) {

            if (board[0][j] == 'X' && board[1][j] == 'X' && board[2][j] == 'X') return "A";
            if (board[0][j] == 'O' && board[1][j] == 'O' && board[2][j] == 'O') return "B";
        }

        // check if there are three of the same (non-empty) character filling any diagonals
        if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') return "A";
        if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') return "B";

        // similarly check for anti-diagonal
        if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') return "A";
        if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') return "B";


        // Winner not found so far, so either result will be draw or pending

        // If not winner so far, and board is completely filled, i.e., total moves = n = 9 => draw
        // And if board is still left to be filled i.e. n != 9 => result yet to be decided => pending

        // moves.size() == no. of non-empty char in board i.e. count of chars != ' '
        int count = 0;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[i][j] != ' ') count++;
            }
        }

        if(count == 9) {
            return "Draw";
        }

        return "Pending";
    }

    string tictactoe(vector<vector<int>>& moves) {
        // Simple implementation based (only 1 solution => optimal)
        // T.C: O(2*n) + O(2m^2) + O(2*m), since m = 3, which is comparable to n <= 9
        // S.C: O(m^2), to evaluate the result, m = 3

        int n = moves.size();

        // Empty board (with empty squares denoted by ' ') of 3x3 size
        vector<vector<int>> board(3, vector<int>(3, ' '));

        // fill the board, conduct the game

        // A starts 1st, so he fills all the even index moves of the moves
        // matrix B fills all the odd index moves
        for (int i = 0; i < n; i++) {

            int r = moves[i][0];
            int c = moves[i][1];
            if (i % 2 == 0) {
                // A puts 'X'
                board[r][c] = 'X';
            } else {
                // B puts 'O'
                board[r][c] = 'O';
            }
        }

        // Check the filled board to find the result
        return checkBoard(board);
    }
};