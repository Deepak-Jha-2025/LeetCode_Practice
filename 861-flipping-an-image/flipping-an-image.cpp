class Solution {
public:
    void reverse(vector<int>& v) {
        int n = v.size();

        // // 2 ptrs
        // int l = 0, r = n-1;

        // while(l <= r) {
        //     int temp = v[l];
        //     v[l] = v[r] ^ 1;
        //     v[r] = temp ^ 1;
        //     l++, r--;
        // }

        // 1 ptr or idx
        for(int i=0; i<n/2; i++) {
            int temp = v[i];
            v[i] = v[n-1-i] ^ 1; // to flip a bit, xor it with 1 (0 ^ 1 = 1 && 1 ^ 1 = 0)
            v[n-1-i] = temp ^ 1;
        }

        if(n % 2 != 0) {
            // n is odd and a centre element exists that is still left out to flip
            v[n/2] ^= 1;
        }
    }

    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        // Improved Brute 
        // T.C: O(n * n/2)
        // S.C: O(1)

        int n = image.size();

        // O(n * n/2)
        for(int i=0; i<n; i++) {
            reverse(image[i]);
        }

        return image;
    }
};