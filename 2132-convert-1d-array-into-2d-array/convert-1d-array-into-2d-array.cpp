class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // Straight forward implementation based
        // T.C: O(m*n)
        // S.C: O(m*n) to return the ans


        vector<vector<int>> ans;

        if(original.size() != m*n) {
            return ans;
        }
        
        // 2 ptr method
        int i=0, j=0;

        int l = original.size();
        while(i<l && j<l) {
            
            j = i;
            while((j+1) % n != 0) {
                j++;
            }

            // The moment (j+1) % n == 0 => j+1 = k*n => j = k*n - 1, where k is the row no. in ans
            // And the row will be from i to j

            vector<int> ithRow(original.begin() + i, original.begin() + (j+1));

            ans.push_back(ithRow);

            i = j+1;
        }


        return ans;
    }
};