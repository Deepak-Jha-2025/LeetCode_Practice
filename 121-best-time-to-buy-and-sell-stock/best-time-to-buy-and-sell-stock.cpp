class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0], profit = 0;

        for(int i=1; i<n; i++) {
            int costPrice = mini;
            int sellPrice = prices[i];

            profit = max(profit, sellPrice - costPrice);
            mini = min(mini, prices[i]); // continuously keep track of minimum
        }

        return profit;
    }
};