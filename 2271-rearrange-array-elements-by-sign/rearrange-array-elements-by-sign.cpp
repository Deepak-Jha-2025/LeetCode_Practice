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


        // // Optimal solution
        // int n = nums.size();
        // vector<int> ans(n, 0);

        // // Starting indices of 1st positive and negative numbers
        // int posIndex = 0, negIndex = 1;
        
        // // Iterate and place while traversing
        // for(int i=0; i<n; i++) {
        //     if(nums[i] < 0) {
        //         ans[negIndex] = nums[i];
        //         negIndex += 2;
        //     }
        //     else {
        //         ans[posIndex] = nums[i];
        //         posIndex += 2;
        //     }
        // }

        // return ans;


        // Variety-2 (if no. of positives != no. of negatives, either one is greater)
        // Optimal won't work, so jump back to brute force

        // 2 lists needed to store the pos, neg in relative order
        vector<int> pos, neg;

        // Iterate the original array and store the pos and neg
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i] > 0) {
                pos.push_back(nums[i]);
            }
            else {
                neg.push_back(nums[i]);
            }
        }

        // Possible 2 cases
        if(pos.size() > neg.size()) {
            // Iterate for as many negatives are there, same no. of positives will also be taken
            for(int i=0; i<neg.size(); i++) {
                nums[2*i] = pos[i];
                nums[2*i+1] = neg[i];

                // This makes sure that for eg: if 2 negatives are there, 4 elemnts are done
                // (i.e. twice the no. of neg elements or 2*neg.size()) 
                // 2 neg and 2 pos, basically all the neg are done
            }

            // Now, for the remaining pos no.s
            
            // No. of left pos no.s  = pos.size() - neg.size()
            // No. of taken pos no.s = as many neg no.s are there = neg.size() = 2
            // Reamining pos no.s will start from index = neg.size() = 2

            // For arr[], 4 elements filled = twice the no. of neg elements = 2*neg.size()
            int idx = neg.size() * 2;
            for(int i=neg.size(); i<pos.size(); i++) {
                nums[idx] = pos[i];
                idx++;
            } 
        }
        else {
            // This will also cover the case if pos.size() == neg.size()

            // Here, everything is same, just neg are in excess and pos are less
            // So, just exchange neg and pos

            // Iterate for as many positives are there, same no. of negatives will also be taken
            for(int i=0; i<pos.size(); i++) {
                nums[2*i] = pos[i];
                nums[2*i+1] = neg[i];

                // This makes sure that for eg: if 2 pos are there, 4 elemnts are done
                // (i.e. twice the no. of pos elements or 2*pos.size()) 
                // 2 neg and 2 pos, basically all the neg are done
            }

            // Now, for the remaining neg no.s
            
            // No. of left neg no.s  = neg.size() - pos.size()
            // No. of taken neg no.s = as many pos no.s are there = pos.size() = 2
            // Reamining neg no.s will start from index = pos.size() = 2

            // For arr[], 4 elements filled = twice the no. of pos elements = 2*pos.size()
            int idx = pos.size() * 2;
            for(int i=pos.size(); i<neg.size(); i++) {
                nums[idx] = neg[i];
                idx++;
            }
        }

        return nums;
    }
};