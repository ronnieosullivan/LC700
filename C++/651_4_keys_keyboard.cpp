// Solution 1:
// DP: 
// it is a little like greedy. the best solution must have the following formate:
// A A A A A ... A A Ctrl-A Ctrl-C Ctrl-P ... Ctrl-P
// DP will decide the max outcome among all possible j to start Ctrl-A
class Solution {
public:
    int maxA(int N) {
        vector<int> dp(N + 1, 0);
        for (int i = 0; i <= N; ++i) {
            dp[i] = i;
            for (int j = 1; j < i - 2; ++j) {
                dp[i] = max(dp[i], dp[j] * (i - j - 1));
            }
        }
        return dp[N];
    }
};