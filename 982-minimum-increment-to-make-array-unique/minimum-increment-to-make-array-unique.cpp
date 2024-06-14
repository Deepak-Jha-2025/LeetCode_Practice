class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // Optimal Solution (Approach - 1) (only optimal under smaller constraints)
        // Somewhat like counting sort

        int n = nums.size();
        int maxElement = *max_element(begin(nums), end(nums));

        vector<int> count(maxElement + n, 0); // store the freq of each element

        for(int i=0; i<n; i++) {
            count[nums[i]]++;
        }

        int moves = 0;
        for(int i=0; i<n + maxElement - 1; i++) {
            if(count[i] <= 1) {
                continue;
            }

            int extra = count[i] - 1;
            count[i+1] += extra;
            count[i] = 1;
            moves += extra;
        }

        return moves;
    }
};