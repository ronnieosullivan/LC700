class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int m = days[0].size(), n = flights.size(), res = 0;
        vector<int> dp(n, INT_MIN);
        dp[0] = 0;
        for (int k = 0; k < m; k++) {
            vector<int> t(n, INT_MIN);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j || flights[i][j]) {
                        t[j] = max(t[j], days[j][k] + dp[i]);
                    }
                }
            }
            dp = t;
        }
        for (int i = 0; i < n; i++) {
            res = max(res, dp[i]);
        }
        return res;
    }
};