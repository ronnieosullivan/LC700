class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        string res;
        const int kMaxWordLen = 10;      
        unordered_set<string> dict(words.begin(), words.end());

        int n = S.length();
        vector<int> bolded(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int l = 1; l <= min(n - i, kMaxWordLen); ++l) {
                if (dict.count(S.substr(i, l))) {
                    fill(bolded.begin() + i, bolded.begin() + i + l, 1);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (bolded[i] && (i == 0 || !bolded[i - 1])) res += "<b>";
            res += S[i];
            if (bolded[i] && (i == n - 1 || !bolded[i + 1])) res += "</b>";
        }

        return res;
    }
};