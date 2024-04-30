class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // // Brute force
        // int n = nums.size();
        // for(int i=0; i<n; i++) {
        //     // for(int j=0; j<n; j++) {
        //     for(int j=i+1; j<n; j++) {
        //         // if(i==j) {
        //         //     continue;
        //         // }
        //         if(nums[i] + nums[j] == target) {
        //             return {min(i,j), max(i,j)};
        //         }
        //     }
        // }
        // return {-1, -1};


        // Better Solution
        int n = nums.size();
        // map<int, int> mpp;
        unordered_map<int, int> mpp; // Saves time (refer STL by LUV source code, on github)

        for(int i=0; i<n; i++) {
            int a = nums[i];
            int more = target - a;

            if(mpp.find(more) != mpp.end()) {
                // return "Yes"; // variety 1 of this problem(discussed by striver)
                return {mpp[more], i}; // mpp[more] < i (since it's presence in the map ensures that it was already encountered in the array 'before(meaning at some idx < i)' the current ith element)
            }

            // mpp[a] = i;
            // mpp.insert(make_pair(a, i));
            mpp.insert({a, i});
        }

        return {-1, -1};
    }
};