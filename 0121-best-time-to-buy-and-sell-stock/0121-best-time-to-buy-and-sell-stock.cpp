class Solution {
public:
    int maxProfit(vector<int>& price) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int i = 0; i < price.size(); i++) {
            
            minPrice = min(minPrice, price[i]);

            maxProfit = max(maxProfit, price[i] - minPrice);
        }

        return maxProfit;
    }
};