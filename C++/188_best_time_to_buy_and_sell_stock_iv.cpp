// If k is larger than prices.size() - 1, we don't have to dp...
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;
        if (k >= prices.size() - 1) {
            int res = 0;
            for (int i = 1; i < prices.size(); ++i) {
                res += max(0, prices[i] - prices[i - 1]);
            }
            return res;
        }
        vector<int> A(k + 1), B(k + 1);
        for (int i = 1; i < prices.size(); ++i) {
            int diff = prices[i] - prices[i - 1];
            for (int j = k; j >= 1; j--) {
                A[j] = max(B[j - 1], A[j]) + diff;
                B[j] = max(A[j], B[j]);
            }
        }
        return B[k];
    }
};