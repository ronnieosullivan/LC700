class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> m;
        for (auto t : transactions) {
            m[t[0]] -= t[2];
            m[t[1]] += t[2];
        }
        vector<int> accnt(m.size());
        int n = 0;
        for (auto a : m) {
            if (a.second != 0) accnt[n++] = a.second;
        }
        return helper(accnt, 0, 0, n);
    }
    int helper(vector<int>& accnt, int start, int cur, int n) {
        while (start < n && accnt[start] == 0) start++;
        if (start == n) return cur;
        int res = INT_MAX;
        for (int i = start + i; i < n; i++) {
            if ((accnt[i] < 0 && accnt[start] > 0) || (accnt[i] > 0 && accnt[start] < 0)) {
                accnt[i] += accnt[start];
                res = min(res, helper(accnt, start + 1, cur + 1, n));
                accnt[i] -= accnt[start];
            }
        }
        return res;
    }
};