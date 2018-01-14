class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> next(n);
        for (int i = 1; i < n; i++) {
            int j = next[i - 1];
            while (j > 0 && s[i] != s[j]) j = next[j - 1];
            next[i] = j + (s[i] == s[j]);
        }
        return next[n - 1] && (next[n - 1] % (n - next[n - 1]) == 0);
    }
};