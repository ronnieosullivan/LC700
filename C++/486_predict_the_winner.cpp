// Solution 1:
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return canWin(nums, 0, n - 1, dp) >= 0;
    }
    int canWin(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
        if (dp[i][j] == -1) {
            dp[i][j] = (i == j) ? nums[i] : max(nums[i] - canWin(nums, i + 1, j, dp), nums[j] - canWin(nums, i, j - 1, dp));
        }
        return dp[i][j];
    }
};

// Solution 2:
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) dp[i][i] = nums[i];
        for (int len = 1; len < n; ++len) {
            for (int i = 0, j = len; j < n; ++i, ++j) {
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};