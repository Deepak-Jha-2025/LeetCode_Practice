class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // // Better solution 
        // // T.C = O(N*logN) + O(N)
        // // S.C = O(N)

        // // map to store the count
        // map<int, int> mpp;

        // // Iterate in the array and store the counts --> O(N*log(N))
        // int n = nums.size();
        // for(int i=0; i<n; i++) {
        //     mpp[nums[i]]++;

        //     // auto it = mpp.find(nums[i]);
        //     // if(it == mpp.end()) {
        //     //     mpp[nums[i]] = 1;
        //     //     // mpp.insert({nums[i], 1});
        //     //     // mpp[nums[i]] = mpp[nums[i]] + 1; // This handles both if-else cases automatically
        //     // }
        //     // else {
        //     //     mpp[nums[i]]++;
        //     // }
        // }

        // // Iterate in the map and find the majority element --> O(N) (worst case if all elements unique)
        // for(auto pr : mpp) {
        //     if(pr.second > n/2) {
        //         return pr.first;
        //     }
        // }
        // return -1;



        // Optimal Solution (Moore's Voting Algorithm)

        // Take the 2 variables, el and cnt
        int el;
        int cnt = 0;

        // Iterate and apply the MVE
        int n = nums.size();
        for(int i=0; i<n; i++) {
            // Start with a check for a new section/part/array
            if(cnt == 0) {
                el = nums[i];
                cnt++;
            }
            // else if cnt != 0 but curr. element = el
            else if(nums[i] == el) {
                cnt++;
            }
            // else if cnt != 0 but curr. element != el
            else {
                cnt--;
            }
        }

        // Iterate again and check if the obtained excess element in el == majority element
        int cnt1 = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] == el) {
                cnt1++;
            }
        }

        if(cnt1 > n/2) {
            return el;
        }
        return -1; // majority element does not exist
    }
};