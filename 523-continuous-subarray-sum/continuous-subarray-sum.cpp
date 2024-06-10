class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // Better solution

        unordered_map<int, int> preSumRemainder;
        // preSumRemainder.insert({0, -1});
        preSumRemainder[0] = -1;

        int sum = 0;
        int rem = 0;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            sum += nums[i];
            rem = sum % k;

            if(preSumRemainder.find(rem) != preSumRemainder.end()) {
                if(i - preSumRemainder[rem] >= 2) {
                    return true;
                }
            }
            else {
                // preSumRemainder.insert({rem, i});
                preSumRemainder[rem] = i;
            }
        }

        return false;
    }
};