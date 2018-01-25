class Solution {
public:
    int strStr(string t, string p) {
        int m = t.size(), n = p.size(), i = 0, j = 0;
        vector<int> next(n, 0);
        getNext(p, next);
        while (i < m && j < n) {
            while (j > 0 && t[i] != p[j]) j = next[j - 1];
            j += (t[i] == p[j] ? 1 : 0);
            i++;
        }
        return (j == n) ? i - j : -1;
    }
    void getNext(const string& p, vector<int>& next) {
        int n = p.size();
        for (int i = 1; i < n; ++i) {
            int j = next[i - 1];
            while (j > 0 && p[i] != p[j]) j = next[j - 1];
            next[i] = j + (p[i] == p[j]);
        }
    }
};