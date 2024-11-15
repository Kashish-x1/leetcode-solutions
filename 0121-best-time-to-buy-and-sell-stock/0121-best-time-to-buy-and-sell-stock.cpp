class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int n = prices.size();
        int minprice = prices[0];
        for(int i = 1;i<n;i++){
            int cost = prices[i] - minprice;
            maxprofit = max(maxprofit ,cost);
            minprice = min(minprice ,prices[i]);
        }
        return maxprofit;
    }
};