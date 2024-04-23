class Solution {
public:
    void rotate(vector<int>& arr, int d) {
        // // Brute Force

        // int n = arr.size();
        // d = d % n;

        // // int temp[d];
        // vector<int> temp;
        // for(int i=n-d; i<n; i++) {
        //     // temp[i-(n-d)] = arr[i];
        //     temp.push_back(arr[i]);
        // }   

        // for(int i=n-d-1; i>=0; i--) {
        //     arr[i+d] = arr[i];
        // }

        // for(int i=0; i<d; i++) {
        //     arr[i] = temp[i];
        // }

        // +++++++++++++++++++++++++++++++++++++++++++++++++++

        // Optimal approach
        int n = arr.size();
        d = d % n;

        reverse(arr.begin(), arr.begin() + (n-d));
        reverse(arr.begin()+(n-d), arr.begin() + n);
        reverse(arr.begin(), arr.begin() + n);
    }
};