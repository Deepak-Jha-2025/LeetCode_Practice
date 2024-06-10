class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Optimal solution
        
        unordered_map<int, int> preSumMap;

        int preSum = 0;
        int cnt = 0;

        // inserting (0,1)
        // preSumMap.insert({0,1});
        preSumMap[0] = 1;

        int n = nums.size();
        for(int i=0; i<n; i++) {
            preSum += nums[i];
            int removeSum = preSum - k;

            if(preSumMap.find(removeSum) != preSumMap.end()) {
                cnt += preSumMap[removeSum];
            }

            // auto it = preSumMap.find(preSum);
            // if(it == preSumMap.end()) {
            //     // occurs 1st time
            //     preSumMap.insert({preSum, 1});
            // }
            // else {
            //     // already exists, so just increment the count
            //     // it->second++;
            //     preSumMap[preSum]++;
            // }

            // Shortcut statement for above
            preSumMap[preSum] = preSumMap[preSum] + 1; // directly inserts 1, i.e. preSum occurs the 1st time if not present
                                                       // else if already present, then just increments the count
        }

        return cnt;
    }
};