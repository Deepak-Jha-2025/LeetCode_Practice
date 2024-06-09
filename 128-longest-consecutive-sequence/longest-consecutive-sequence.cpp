class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Better Solution
        if(nums.size() == 0) {
            return 0;
        }
        
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int longest = 1;
        int cntCurr = 0;
        int lastSmaller = INT_MIN;

        for(int i=0; i<n; i++) {
            if(nums[i] - 1 == lastSmaller) {
                cntCurr++;
                lastSmaller = nums[i];
            }
            else if(nums[i] != lastSmaller) {
                cntCurr = 1;
                lastSmaller = nums[i];
            }

            longest = max(longest, cntCurr);
        }

        return longest;
    }
};