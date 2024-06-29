class Solution {
public:
    int countLiveNeighbors(vector<vector<int>>& board, int row, int col) {
        int m = board.size();
        int n = board[0].size();

        int neighbors = 0;
        for(int i=row-1; i<=row+1; i++) {
            for(int j=col-1; j<=col+1; j++) {

                if((i==row && j==col) || i<0 || j<0 || i==m || j==n) {
                    continue;
                }

                if(board[i][j] == 1 || board[i][j] == 3) {
                    neighbors++;
                }
            }
        }

        return neighbors;
    }

    void gameOfLife(vector<vector<int>>& board) {
        // Better solution (Optimal Solution)

        // Similar approach to brute force of "set matrix zeros" ques
        /* Original   |   New   |   State(modified temporarily)
              0       |    0    |     0
              1       |    0    |     1
              0       |    1    |     2
              1       |    1    |     3
        */

        // T.C: O(2mn)
        // S.C: O(1)

        int m = board.size();
        int n = board[0].size();

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {

                int neighbors = countLiveNeighbors(board, i, j);

                if(board[i][j] == 1) {
                    
                    if(neighbors == 2 || neighbors == 3) {
                        // It lives, 1 --> 1, so temporarily change it to 3
                        // else if it dies, 1 --> 0, its temp state is also 1, so just leave it
                        board[i][j] = 3;
                    }
                }
                else {
                    if(neighbors == 3) {
                        // it becomes live, 0 --> 1, so temporarily change it to 2
                        // else if it stays dead, 0 --> 0, its temp state is also 0, so just leave it
                        board[i][j] = 2;
                    }
                }
            }
        }

        // Now, convert the temp o/p state to the actual new state
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                
                if(board[i][j] == 1) {
                    board[i][j] = 0;
                }

                if(board[i][j] == 2 || board[i][j] == 3) {
                    board[i][j] = 1;
                }
            }
        }

    }
};