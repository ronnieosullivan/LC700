class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            if (s[i - 1] != '0') dp[i] = dp[i - 1];
            if (i != 1 && (s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] <= '6')) dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};