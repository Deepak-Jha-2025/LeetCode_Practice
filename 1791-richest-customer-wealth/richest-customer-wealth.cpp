class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        // Straight forward implementation based
        // Only one solution => Optimal solution
        // Time: O(m*n)
        // Space: O(1)

        int m = accounts.size();
        int n = accounts[0].size();

        int maxWealth = 0;
        for(int i=0; i<m; i++) {
            int currWealth = 0;
            for(int j=0; j<n; j++) {
                currWealth += accounts[i][j];
            }

            maxWealth = max(maxWealth, currWealth);
        }

        return maxWealth;
    }
};