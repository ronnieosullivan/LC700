// Solution 1:
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) return true;
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        unordered_map<int, bool> dp;
        return canWin(maxChoosableInteger, desiredTotal, 0, dp);
    }
    bool canWin(int n, int total, int used, unordered_map<int, bool>& dp) {
        if (dp.count(used)) return dp[used];
        for (int i = 0; i < n; i++) {
            int mask = (1 << i);
            if (mask & used) continue;
            if (total <= i + 1 || !canWin(n, total - (i + 1), mask | used, dp)) {
                dp[used] = true;
                return true;
            }
        }
        dp[used] = false;
        return false;
    }
};