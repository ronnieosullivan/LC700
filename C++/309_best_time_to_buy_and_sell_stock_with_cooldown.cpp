// T[i][k][0] = max(T[i - 1][k][0], T[i - 1][k][1] + price)
// T[i][k][1] = max(T[i - 2][k][0] - price, T[i - 1][k][1])
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN, prebuy = 0, sell = 0, presell = 0;
        for (int price : prices) {
            prebuy = buy;
            buy = max(presell - price, prebuy);
            presell = sell;
            sell = max(prebuy + price, presell);
        }
        return sell;
    }
};