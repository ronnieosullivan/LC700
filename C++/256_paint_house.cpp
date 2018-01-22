class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        vector<int> dp = costs[0];
        for (int i = 1; i < costs.size(); i++) {
            vector<int> t(3, INT_MAX);
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (j != k) t[k] = min(t[k], dp[j] + costs[i][k]);
                }
            }
            dp = t;
        }
        auto it = min_element(dp.begin(), dp.end());
        return *it;
    }
};