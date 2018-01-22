class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        if (dictionary.empty()) return to_string((int)target.size());
        auto v = generateAbbreviations(target);
        sort(v.begin(), v.end(), [](const string& a, const string& b){
            return a.length() == b.length() ? a < b : a.length() < b.length();
        });
        for (auto& a : v) {
            bool no_conflict = true;
            for (auto b : dictionary) {
                if (valid(b, a)) {
                    no_conflict = false;
                    break;
                }
            }
            if (no_conflict) return a;
        }
        return "";
    }
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
    bool valid(string word, string abbr) {
        int m = word.size(), n = abbr.size(), p = 0, cnt = 0;
        for (int i = 0; i < abbr.size(); ++i) {
            if (abbr[i] >= '0' && abbr[i] <= '9') {
                if (cnt == 0 && abbr[i] == '0') return false;
                cnt = 10 * cnt + abbr[i] - '0';
            } else {
                p += cnt;
                if (p >= m || word[p++] != abbr[i]) return false;
                cnt = 0;
            }
        }
        return p + cnt == m;
    }
};