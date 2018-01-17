class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        string res("");
        int n = s.size(), end = 0;
        vector<bool> bold(n);
        for (int i = 0; i < n; i++) {
            for (auto& word : dict) {
                int len = word.length();
                if (i + len <= n && word == s.substr(i, len)) {
                    end = max(end, i + len);
                }
            }
            bold[i] = end > i;
        }
        for (int i = 0; i < n; i++) {
            if (!bold[i]) {
                res.push_back(s[i]);
                continue;
            }
            int start = i;
            while (i < n && bold[i]) i++;
            res += "<b>" + s.substr(start, i - start) + "</b>";
            i--;
        }
        return res;
    }
};