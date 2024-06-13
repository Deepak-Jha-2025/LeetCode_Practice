class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        // Better Solution

        // Intuition: rightmost student should take the rightmost seat and leftmost student should take the leftmost
        // seat, as logically, it will be respectively the closest to them. Then subsequently, the 2nd leftmost and 
        // the 2nd rightmost student should take the 2nd leftmost and 2nd right most seat respectively, and so on.

        // Basically if seat positions and student positions are sorted, then optimally the nearest seat for ith
        // student will be ith seat.

        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int cnt = 0;
        int n = seats.size();
        for(int i=0; i<n; i++) {
            cnt += abs(students[i] - seats[i]);
        }

        return cnt;
    }
};