class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // Better solution (Approach 1)
        // T.C: O(nlogn) + O(n)

        int n = nums.size();
        sort(nums.begin(), nums.end()); // nlogn

        int moves = 0;
        for(int i=1; i<n; i++) {
            if(nums[i-1] >= nums[i]) {
                moves += (nums[i-1] - nums[i] + 1);
                nums[i] = nums[i-1] + 1;
            }
        }

        return moves;
    }
};