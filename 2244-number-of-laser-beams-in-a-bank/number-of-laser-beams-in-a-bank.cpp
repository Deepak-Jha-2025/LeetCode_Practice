class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        // Optimal Solution (Greedy Approach) 
        // Optimizes the extra space of the better solution from O(m) to O(1)
        // Eliminates the need of hashmap/hashtable

        // T.C: O(m*n)
        // S.C: O(1)

        int m = bank.size();
        int n = bank[0].size();

        int upperLasers = 0; // no. of lasers on upper floor
        int lowerLasers = 0; // no. of lasers on lower floor

        int totalLasers = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(bank[i][j] == '1') {
                    lowerLasers++;
                }
            }

            if(lowerLasers != 0) {
                totalLasers += (upperLasers * lowerLasers);
                upperLasers = lowerLasers;
                lowerLasers = 0;
            }
        }

        return totalLasers;
    }
};