class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int n = S.size();
        string res("");
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (S[i] == '-') continue;
            res.push_back(toupper(S[i]));
            cnt++;
            if (cnt % K == 0) res.push_back('-');
        }
        if (res.back() == '-') res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};