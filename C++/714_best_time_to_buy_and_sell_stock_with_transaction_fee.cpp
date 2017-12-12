// Solution 1:
// T[i][0] = max(T[i - 1][0], T[i - 1][1] + price);
// T[i][1] = max(T[i - 1][0] - price - fee, T[i - 1][1]);
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int presell = 0, sell = 0, buy = INT_MIN;
        for (auto price : prices) {
            presell = sell;
            sell = max(sell, buy + price);
            buy = max(buy, presell - price - fee);
        }
        return sell;
    }
};