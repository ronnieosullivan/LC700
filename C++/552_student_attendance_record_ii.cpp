class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1000000007;
        vector<vector<int>> dp(2, vector<int>(3, 1));
        for (int i = 1; i <= n; i++) {
            vector<vector<int>> t = dp;
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 3; k++) {
                    int val = t[j][2]; // P
                    if (j > 0) val = (val + t[j - 1][2]) % MOD; // A
                    if (k > 0) val = (val + t[j][k - 1]) % MOD; // L
                    dp[j][k] = val;
                }
            }
        }
        return dp[1][2];
    }
};