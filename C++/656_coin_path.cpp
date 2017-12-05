// Solution 1:
// dp
class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        int n = A.size();
        vector<int> next(n);
        vector<long long> dp(n);
        vector<int> res;
        for (int i = n - 2; i >= 0; i--) {
            long long minCost = INT_MAX;
            for (int j = i + 1; j <= i + B && j < n; j++) {
                if (A[j] >= 0) {
                    long cost = A[i] + dp[j];
                    if (cost < minCost) {
                        minCost = cost;
                        next[i] = j;
                    }
                }
            }
            dp[i] = minCost;
        }
        
        int i = 0;
        for (; i < n && next[i] > 0; i = next[i]) {
            res.push_back(i + 1);
        }
        res.push_back(n);
        if (i == n - 1 && A[i] >= 0) return res;
        else return {};
    }
};

// Solution 2:
// recursion: TLS
class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        int index = 0, curCost = A[0], minCost = INT_MAX;
        vector<int> res, cur, dp(A.size(), INT_MAX);
        cur.push_back(1); // always start from index 1
        helper(A, B, index, dp, curCost, cur, minCost, res);
        return res;
    }
    void helper(vector<int>& A, int B, int index, vector<int>& dp, int curCost, vector<int>& cur, int& minCost, vector<int>& res) {
        if (curCost > minCost || curCost > dp[index]) return;
        dp[index] = min(dp[index], curCost);
        if (index == A.size() - 1) {
            if (curCost < minCost) {
                minCost = curCost;
                res = cur;
            }
            else if (curCost == minCost) {
                if (cur < res) res = cur;
            }
            else return;
        }
        for (int i = index + 1; i < A.size() && i - index <= B; i++) {
            if (A[i] == -1) continue;
            cur.push_back(i + 1);
            helper(A, B, i, dp, curCost + A[i], cur, minCost, res);
            cur.pop_back();
        }
    }
};