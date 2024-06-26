class Solution {
public:
    void reverse(vector<int>& v) {
        int n = v.size();

        // // 2 ptrs
        // int l = 0, r = n-1;

        // while(l < r) {
        //     swap(v[l], v[r]);
        //     l++, r--;
        // }

        // 1 ptr or idx
        for(int i=0; i<n/2; i++) {
            swap(v[i], v[(n-1)-i]);
        }
    }

    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        // Brute force

        int n = image.size();

        // O(n * n/2)
        for(int i=0; i<n; i++) {
            reverse(image[i]);
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                image[i][j] = !image[i][j];
            }
        }

        return image;
    }
};