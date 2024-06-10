class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected;

        int n = heights.size();
        for(int i=0; i<n; i++) {
            expected.push_back(heights[i]);
        }

        sort(expected.begin(), expected.end());

        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(expected[i] != heights[i]) {
                cnt++;
            }
        }

        return cnt;
    }
};