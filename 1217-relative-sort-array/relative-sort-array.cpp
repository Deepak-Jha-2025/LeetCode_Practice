class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // Better Solution
        map<int, int> mpp;

        int m = arr1.size();
        int n = arr2.size();

        for(int i=0; i<m; i++) {
            mpp[arr1[i]]++;
        }

        int cnt=0, temp = 0;
        for(int i=0; i<n; i++) {
            temp = 0;
            while(temp < mpp[arr2[i]]) {
                arr1[cnt] = arr2[i];
                temp++, cnt++;
            }

            mpp.erase(arr2[i]);
        }

        for(auto it : mpp) {
            temp = 0;
            while(temp < it.second) {
                arr1[cnt] = it.first;
                temp++, cnt++;
            }
        }

        return arr1;
    }
};