class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (auto& a : wordDict) dict.insert(a);
        int n = s.size();
        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (dp[j]) {
                    string t = s.substr(j, i - j + 1);
                    if (dict.count(t)) {
                        dp[i + 1] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};