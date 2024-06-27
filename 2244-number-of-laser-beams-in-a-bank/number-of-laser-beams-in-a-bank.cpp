class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        // Better Solution (Brute is somewhat O(n^3 or n^4))

        // T.C: O(m*n) + O(m)
        // S.C: O(m)

        // Using hash map or hash table
        int m = bank.size();
        int n = bank[0].size();

        // Use a hash table to count the number of 1s or security devices per floor
        // Index of table are mapped directly to indices of each floor/row of the bank matrix
        // idx = floor/row , devices[idx] = no. of dev in that floor

        vector<int> devices(m, 0); // O(m) for initialization

        // Count the no. of devices --> O(m*n)
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(bank[i][j] == '1') {
                    devices[i]++;
                }
            }
        }

        // Now, by PnC formula nCr, no. of lasers b/w any 2 subsequent floors with non-zero no. of devices
        // = n1C1 * n2C2, where n1 = no. of devices in upper floow, n2 = no. of devices in lower floor
        // = n1 * n2

        // Count the total laser beams by above logic using 2 ptr method
        int i=0; // to find upper floor with non-zero devices
        int j=0; // to find the next subsequent lower floor with non-zero no. of devices
        int totalLasers = 0;

        // 1st, i will iterate till it finds a floor with non-zero no. of devices, this is the upper floor
        while(i < m && devices[i] == 0) {
            i++;
        }

        while(i < m) {

            // from the next floor below, start looking for the next floor with non-zero no. of devices, this
            // will be the lower floor
            j = i+1; 

            while(j < m && devices[j] == 0) {
                j++;
            }

            if(j < m) {
                totalLasers += (devices[i] * devices[j]);
            }

            // Now, lower floor will become upper floor for next upcoming floor (kyuki is floor se bhi toh
            // nichle floor me laser jayegi, har floor upar aur niche dono taraf laser marega)
            i = j;
        }

        return totalLasers;

    }
};