class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        int consecOddCnt = 0;

        for(int i=0; i<n; i++) {
            if(arr[i] % 2 != 0) {
                consecOddCnt++;
            }
            else {
                consecOddCnt = 0;
            }

            if(consecOddCnt == 3) return true;
        }

        return false;
    }
};