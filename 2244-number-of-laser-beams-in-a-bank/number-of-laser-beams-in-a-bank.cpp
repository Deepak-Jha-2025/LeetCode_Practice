class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        // Optimal Solution (Greedy Approach) 
        // Optimizes the extra space of the better solution from O(m) to O(1)

        // how does this thought come up in the 1st place?
        /* Look at the better solution, while we iterate in the hash table
           to calculate the total number of beams, everytime we just need 2 values,
           the prevDeviceCount/upperFloor and the currentDeviceCount/lowerFloor, once we calc a product
           from the 2, then the currentDeviceCount becomes the prevDeviceCount and we go on to next for 
           the next currentDeviceCount/lowerFloor, there is no further need of the used prevDeviceCount(s)
           
           This gives us the idea, that there was never a need in the 1st place to store 
           all the counts, just the current and its prev count are sufficient at each stage */

        // Eliminates the need of hashmap/hashtable

        // T.C: O(m*n)
        // S.C: O(1)

        int m = bank.size();
        int n = bank[0].size();

        int prevDeviceCount = 0;    // no. of lasers on upper floor/ previous floor/row
        int currentDeviceCount = 0; // no. of lasers on lower floor/ current floor/row

        int totalLasers = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(bank[i][j] == '1') {
                    currentDeviceCount++;
                }
            }

            if(currentDeviceCount != 0) { // means current row has devices

                // in 1st iteration, total = 0, b/z there is no prevDeviceCount yet, so where will the lasers come from
                totalLasers += (prevDeviceCount * currentDeviceCount); 

                prevDeviceCount = currentDeviceCount; // Now, this currentDeviceCount will become the prevDeviceCount for the upcoming currentDeviceCount

                currentDeviceCount = 0; // reset currentDeviceCount to store the no. of devices for the next upcoming row that has got some devices
            }
        }

        return totalLasers;
    }
};