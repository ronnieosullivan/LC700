class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        string cur;
        int n = s.size();
        vector<bool> possible(n + 1, true);
        dfs(s, dict, 0, possible, cur, res);
        return res;
    }
    void dfs(string& s, unordered_set<string>& dict, int start, vector<bool>& possible, string& cur, vector<string>& res) {
        if (start == s.size()) {
            res.push_back(cur.substr(0, cur.size() - 1));
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            string word = s.substr(start, i - start + 1);
            if (dict.count(word) && possible[i + 1]) {
                string t = cur + word + " ";
                int oldSize = res.size();
                dfs(s, dict, i + 1, possible, t, res);
                if (res.size() == oldSize) possible[i + 1] = false;
            }
        }
    }
};