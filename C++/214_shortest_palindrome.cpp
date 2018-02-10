class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        string t = s + "#" + r;
        vector<int> next(t.size());
        for (int i = 1; i < t.size(); i++) {
            int j = next[i - 1];
            while (j > 0 && t[j] != t[i]) j = next[j - 1];
            next[i] = j + (t[i] == t[j]);
        }
        return r.substr(0, s.size() - next.back()) + s;
    }
};