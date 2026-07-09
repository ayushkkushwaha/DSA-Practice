class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int res = 0;
        int minPrice = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minPrice)
                minPrice = prices[i];

            int cost = prices[i] - minPrice;
            res = max(res, cost);
        }

        return res;
    }
};