class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        // Optimal Solution (counting sort, only when constraints are small, like elements in both arrays <= 100)

        int maxPos = 0;
        maxPos = max(seats[0], students[0]);

        int n = seats.size();
        for(int i=1; i<n; i++) {
            maxPos = max(maxPos, max(seats[i], students[i]));
        }

        int m = maxPos;
        vector<int> differences(m+1, 0);

        for(int i=0; i<n; i++) {
            differences[seats[i]]++;
        }

        for(int i=0; i<n; i++) {
            differences[students[i]]--;
        }

        // differences[i] == 0  ==> empty position
        // differences[i] == 1  ==> extra seat in that position
        // differences[i] == -1 ==> extra student without a seat in that position
        

        int moves = 0;
        int unmatched = 0;

        for(int i=1; i<m+1; i++) {
            unmatched += differences[i];
            moves = moves + abs(unmatched);
        }

        return moves;
    }
};