class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // Brute force
        // T.C: O(m*n) + O(m*n)
        // S.C: O(m*n)

        int m = board.size();
        int n = board[0].size();

        int cnt = 0;
        vector<vector<int>> ans(m, vector<int>(n));

        // O(m*n)
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                
                bool leftCheck = false, rightCheck = false;
                cnt = 0; // reset count for each element
                if(i-1>=0) {
                    if(board[i-1][j] == 1) {
                        cnt++;
                    }

                    if(j-1>=0) {
                        if(board[i][j-1] == 1) {
                            cnt++;
                            leftCheck = true;
                        }
                        if(board[i-1][j-1] == 1) {
                            cnt++;
                        }
                    }

                    if(j+1<n) {
                        if(board[i][j+1] == 1) {
                            cnt++;
                            rightCheck = true;
                        }
                        if(board[i-1][j+1] == 1) {
                            cnt++;
                        }
                    }
                }

                if(i+1<m) {
                    if(board[i+1][j] == 1) {
                        cnt++;
                    }

                    if(j-1>=0) {
                        if(board[i][j-1] == 1 && leftCheck == false) {
                            cnt++;
                        }
                        if(board[i+1][j-1] == 1) {
                            cnt++;
                        }
                    }

                    if(j+1<n) {
                        if(board[i][j+1] == 1 && rightCheck == false) {
                            cnt++;
                        }
                        if(board[i+1][j+1] == 1) {
                            cnt++;
                        }
                    }
                }

                if(board[i][j] == 0) {
                    if(cnt == 3) {
                        ans[i][j] = 1;
                    }
                    else {
                        ans[i][j] = 0;
                    }
                }

                if(board[i][j] == 1) {
                    if(cnt < 2 || cnt > 3) {
                        ans[i][j] = 0;
                    }
                    else if(cnt == 2 || cnt == 3) {
                        ans[i][j] = 1;
                    }
                }

            }
        }

        board = ans; // O(m*n) --> only b/z of the return type of the function
    }
};