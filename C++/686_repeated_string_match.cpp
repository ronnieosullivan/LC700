class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int m = A.size(), n = B.size();
        vector<int> next(n);
        for (int i = 1; i < n; ++i) {
            int j = next[n - 1];
            while (j > 0 && B[i] != B[j]) j = next[j - 1];
            next[i] = j + B[i] == B[j];
        }
        int i = 0, j = 0;
        while (i < max(m * 2, n * 2) && j < n) {
            while (j > 0 && A[i % m] != B[j]) j = next[j - 1];
            j += (A[i % m] == B[j] ? 1 : 0);
            i++;
        }
        return (j == n) ? (i / m + (i % m != 0 ? 1 : 0)) : -1;
    }
};