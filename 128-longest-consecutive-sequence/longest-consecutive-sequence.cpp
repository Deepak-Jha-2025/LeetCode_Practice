class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        
        sort(nums.begin(), nums.end());

        int len = 1;
        int maxLen = 1;
        int n = nums.size();

        for(int i=1; i<n; i++) {
            if(nums[i] - nums[i-1] == 1) {
                len++;
            }
            else if(nums[i] - nums[i-1] != 0) {
                maxLen = max(maxLen, len);
                len = 1;
            }
        }

        maxLen = max(maxLen, len); // to check for the last possible consecutive subseq. which will not be checked by the else block (loop will terminate before that)

        return maxLen;
    }
};