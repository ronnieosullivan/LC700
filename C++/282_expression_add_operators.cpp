class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        helper(num, 0, "", 0, 0, target, res);
        return res;
    }
    void helper(const string& num, int start, string path, long long cur, long long multiplier, int target, vector<string>& res) {
        int n = num.size();
        if (start == n) {
            if (cur == (long long)target) res.push_back(path);
            return;
        }
        for (int i = start; i < n; i++) {
            string tmp = num.substr(start, i - start + 1);
            if (tmp.size() > 1 && tmp[0] == '0') return;
            if (!path.empty()) {
                helper(num, i + 1, path + "+" + tmp, cur + stoll(tmp), stoll(tmp), target, res);
                helper(num, i + 1, path + "-" + tmp, cur - stoll(tmp), -stoll(tmp), target, res);
                helper(num, i + 1, path + "*" + tmp, cur - multiplier + multiplier * stoll(tmp), multiplier * stoll(tmp), target, res);
            }
            else {
                helper(num, i + 1, tmp, stoll(tmp), stoll(tmp), target, res);
            }
        }
    }
};