class Solution {
public:
    string encode(string s) {
        int n = s.size();
        vector<vector<string>> dp(n, vector<string>(n, ""));
        for (int len = 1; len <= n; len++) {
            for (int start = 0; start <= n - len; start++) {
                int end = start + len - 1;
                string t = s.substr(start, len);
                dp[start][start + len - 1] = t;
                int index = (t + t).find(t, 1);
                if (index != t.size()) {
                    string abbr = "" + to_string(len / index) + "[" + dp[start][start + index - 1] + "]";
                    if (abbr.length() < t.length()) dp[start][end] = abbr;
                }
                for (int k = start; k < end; k++) {
                    string temp = dp[start][k] + dp[k + 1][end];
                    if (temp.length() < dp[start][end].length()) {
                        dp[start][end] = temp;
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};