
// do this question again from scratch

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = 100000;
        int maxSell = 0;

        for (const auto& price : prices) {
            minBuy = min(price, minBuy);
            maxSell = max(price - minBuy, maxSell);
        }
        return maxSell;
    }
};
