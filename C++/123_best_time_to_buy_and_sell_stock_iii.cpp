// Solution 1:
// A = sell at day i, at most j transactions
// B = sell at any day, at most j transactions
// A[i][j] = max(B[i - 1][j - 1], A[i - 1][j]) + diff; // because we have to sell at day i
// B[i][j] = max(A[i][j], B[i - 1][j]);
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        vector<int> A(3), B(3);
        for (int i = 1; i < prices.size(); ++i) {
            int diff = prices[i] - prices[i - 1];
            for (int j = 2; j >= 1; j--) {
                A[j] = max(B[j - 1], A[j]) + diff;
                B[j] = max(A[j], B[j]);
            }
        }
        return B[2];
    }
};