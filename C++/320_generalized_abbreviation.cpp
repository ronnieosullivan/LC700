// Solution 1:
// recursion
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        helper(word, 0, 0, "", res);
        return res;
    }
    void helper(string word, int i, int cnt, string cur, vector<string> &res) {
        if (i == word.size()) {
            if (cnt > 0) cur += to_string(cnt);
            res.push_back(cur);
        } else {
            helper(word, i + 1, cnt + 1, cur, res);
            helper(word, i + 1, 0, cur + (cnt > 0 ? to_string(cnt) : "") + word[i], res);
        }
    }
};

// Solution 2:
// bit
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        for (int i = 0; i < pow(2, word.size()); ++i) {
            string out = "";
            int cnt = 0;
            for (int j = 0; j < word.size(); ++j) {
                if ((i >> j) & 1) ++cnt;
                else {
                    if (cnt != 0) {
                        out += to_string(cnt);
                        cnt = 0;
                    }
                    out += word[j];
                }
            }
            if (cnt > 0) out += to_string(cnt);
            res.push_back(out);
        }
        return res;
    }
};
