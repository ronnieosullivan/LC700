// Solution 1:
// Best solution.
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> tmp;
        helper(s, 0, 0, {'(', ')'}, tmp); // remove redundant ')'
        vector<string> res;
        for (auto str : tmp) {
            string rev = string(str.rbegin(), str.rend()); // remove redundant '('
            helper(rev, 0, 0, {')', '('}, res);
        }
        for (auto& str : res) {
            reverse(str.begin(), str.end());
        }
        return res;
    }
    void helper(string s, int last_i, int last_j, vector<char> p, vector<string>& res) {
        int cnt = 0;
        for (int i = last_i; i < s.size(); ++i) {
            if (s[i] == p[0]) ++cnt;
            else if (s[i] == p[1]) --cnt;
            if (cnt >= 0) continue;
            for (int j = last_j; j <= i; ++j) {
                if (s[j] == p[1] && (j == last_j || s[j] != s[j - 1])) {
                    helper(s.substr(0, j) + s.substr(j + 1), i, j, p, res);
                }
            }
            return;
        }
        res.push_back(s);
    }
};

// Solution 2:
// 