// Solution 1:
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int len = 1; len <= n; len++) {
            for (int left = 0; left <= n - len; left++) {
                int right = left + len - 1;
                for (int k = left; k <= right; ++k) {
                    dp[left][right] = max(dp[left][right], 
                        (left == 0 ? 1 : nums[left - 1]) * nums[k] * (right >= n - 1 ? 1 : nums[right + 1]) 
                            + (left > k - 1 ? 0 : dp[left][k - 1]) + (k + 1 > right ? 0 : dp[k + 1][right]));
                }
            }
        }
        return dp[0][n - 1];
    }
}