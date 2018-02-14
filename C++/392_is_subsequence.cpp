// Solution 1:
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) ++i;
            ++j;
        }
        return i == s.size();
    }
};

// Solution 2:
class Solution {
public:
    bool isSubsequence(string s, string t) {
        build(t);
        int j = -1;
        for (int i = 0; i < s.size(); i++) {
            if (!_v[j].count(s[i])) return false;
            j = _v[j][s[i]];
        }
        return true;
    }
    void build(const string& t) {
        unordered_map<char, int> m;
        int n = t.size();
        m[t[n - 1]] = n - 1;
        for (int i = n - 2; i >= -1; i--) {
            _v[i] = m;
            m[t[i]] = i;
        }
    }
private:
    unordered_map<int, unordered_map<char, int>> _v;
};