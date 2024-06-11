class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // Brute Force
        vector<int> arr3;
        vector<int> leftOverElements;

        int m = arr1.size();
        int n = arr2.size();

        for(int i=0; i<n; i++) {
            int toFind = arr2[i];

            for(int j=0; j<m; j++) {
                if(arr1[j] == toFind) {
                    arr3.push_back(arr1[j]);
                    arr1[j] = -1;
                }
            }
        }

        for(int i=0; i<m; i++) {
            // Since we marked all elements taken as -ve, whatever is +ve are the leftovers
            if(arr1[i] >= 0) {
                leftOverElements.push_back(arr1[i]);
            }
        }

        sort(leftOverElements.begin(), leftOverElements.end());

        for(int i=0; i<leftOverElements.size(); i++) {
            arr3.push_back(leftOverElements[i]);
        }

        return arr3;
    }
};