class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        // Brute force 

        int cnt = 0;
        int n = seats.size();
        for(int j=0; j<n; j++) {

            int minSeat = INT_MAX;
            int minStudent = INT_MAX;

            int minSeatIdx = -1;
            int minStudIdx = -1;
            
            for(int i=0; i<n; i++) {

                if(seats[i] > 0 && seats[i] < minSeat) {
                    minSeat = seats[i];
                    minSeatIdx = i;
                }

                if(students[i] > 0 && students[i] < minStudent) {
                    minStudent = students[i];
                    minStudIdx = i;
                }

            }

            cnt += abs(minSeat - minStudent);
            seats[minSeatIdx] = -1;
            students[minStudIdx] = -1;
        }

        return cnt;
    }
};