class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> preSumRemainder;

        int n = nums.size();

        // Iterate array and store remainders in map
        int preSum = 0;
        for(int i=0; i<n; i++) {
            // Step 1: Find preSum
            preSum += nums[i];

            // Step 2: Find remainder for that preSum
            int remainder = preSum % k;
            if(remainder < 0) {
                // convert to +ve remainder if -ve
                // logic in copy-3
                remainder += k;
            }

            // Step 3: store the remainder in map
            preSumRemainder[remainder]++;
        }

        // Step 4: iterate in map and find total subarrays with sum % k by PnC logic
        int cnt = 0;
        for(auto it: preSumRemainder) {
            int c = it.second;
            if(it.first == 0) {
                cnt += c;
            }

            if(c >= 2) {
                cnt += (c*(c-1))/2; // nC2 formula where c = n != size of nums[]
            }
        }
        
        return cnt;
    }
};