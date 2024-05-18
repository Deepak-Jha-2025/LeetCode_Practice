class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Better solution

        // map to store the count
        map<int, int> mpp;

        // Iterate in the array and store the counts
        int n = nums.size();
        for(int i=0; i<n; i++) {
            // mpp[nums[i]]++;

            auto it = mpp.find(nums[i]);
            if(it == mpp.end()) {
                mpp[nums[i]] = 1;
                // mpp.insert({num[i], 1});
                // mpp[nums[i]] = mpp[nums[i]] + 1; // This handles both if-else cases automatically
            }
            else {
                mpp[nums[i]]++;
            }
        }

        // Iterate in the map and find the majority element
        // for(auto it = mpp.begin(); it != mpp.end(); it++) {
        for(auto pr : mpp) {
            // if(it->second > n/2) {
            if(pr.second > n/2) {
                return pr.first;
                // return it->first;
            }
        }
        return -1;
    }
};