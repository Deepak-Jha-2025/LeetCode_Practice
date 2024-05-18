class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Better solution

        // map to store the count
        unordered_map<int, int> mpp;

        // Iterate in the array and store the counts --> O(N*log(N))
        int n = nums.size();
        for(int i=0; i<n; i++) {
            mpp[nums[i]]++;

            // auto it = mpp.find(nums[i]);
            // if(it == mpp.end()) {
            //     mpp[nums[i]] = 1;
            //     // mpp.insert({nums[i], 1});
            //     // mpp[nums[i]] = mpp[nums[i]] + 1; // This handles both if-else cases automatically
            // }
            // else {
            //     mpp[nums[i]]++;
            // }
        }

        // Iterate in the map and find the majority element
        for(auto pr : mpp) {
            if(pr.second > n/2) {
                return pr.first;
            }
        }
        return -1;
    }
};