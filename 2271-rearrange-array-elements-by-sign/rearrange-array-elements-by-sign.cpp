class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // // Brute force 
        // int n = nums.size();
        // vector<int> pos, neg;

        // for(int i=0; i<n; i++) {
        //     if(nums[i] > 0) {
        //         pos.push_back(nums[i]);
        //     }
        //     else {
        //         neg.push_back(nums[i]);
        //     }
        // }

        // for(int i=0; i<n/2; i++) {
        //     nums[2*i] = pos[i];
        //     nums[2*i + 1] = neg[i];
        // }

        // return nums;


        // Optimal solution
        int n = nums.size();
        vector<int> ans(n, 0);

        // Starting indices of 1st positive and negative numbers
        int posIndex = 0, negIndex = 1;
        
        // Iterate and place while traversing
        for(int i=0; i<n; i++) {
            if(nums[i] < 0) {
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
            else {
                ans[posIndex] = nums[i];
                posIndex += 2;
            }
        }

        return ans;
    }
};