class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Optimal solution (Kadane's algo - O(n) time, O(1) space)
        int sum = 0, maxi = INT_MIN;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            sum += nums[i];

            if(sum > maxi) {
                maxi = sum;
            }

            if(sum < 0) {
                sum = 0;
            }
        }
        return maxi;
    }
};