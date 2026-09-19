class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() ==1){
            return 0;
        }
        int min_price= INT_MAX, profit=0;
        int n= prices.size();

        for(int i=0; i<n; i++){
            min_price = min(min_price, prices[i]);
            int currProfit = prices[i] - min_price;
            profit = max(profit, currProfit);
        }

        return profit;
    }
};