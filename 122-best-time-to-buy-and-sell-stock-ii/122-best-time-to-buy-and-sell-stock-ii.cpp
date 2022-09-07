class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, currMin = prices[0], currMax = prices[0];
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < currMax) {
                profit += (currMax - currMin);
                currMin = prices[i];
                currMax = prices[i];
            } 
            if (prices[i] > currMin) {
                currMax = prices[i];
            }
            // cout << currMin << " " << currMax << " " << profit << endl;
        }
        profit += (currMax - currMin);
        return profit;
    }
};