class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), res = INT_MIN;
        for (int i = 0; i < m; i++) {
            vector<int> sum(n);
            for (int j = i; j < m; j++) {
                for (int p = 0; p < n; p++) {
                    sum[p] += matrix[j][p];
                }
                int curSum = 0;
                set<int> s = { 0 };
                for (auto a : sum) {
                    curSum += a;
                    auto it = s.lower_bound(curSum - k);
                    if (it != s.end()) res = max(res, curSum - *it);
                    s.insert(curSum);
                }
            }
        }
        return res;
    }
};