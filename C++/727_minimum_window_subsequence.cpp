// Solution 1:
// Not perfect, some details might be optimized
class Solution {
public:
    string minWindow(string S, string T) {
        string res("");
        int n = S.size(), mn = INT_MAX;
        vector<vector<int>> next(n + 1, vector<int>(26, -1));
        vector<int> cur(26, -1);
        for (int i = n - 1; i >= 0; i--) {
            cur[S[i] - 'a'] = i;
            for (int k = 0; k < 26; ++k) {
                next[i][k] = cur[k];
            }
        }
        for (int i = 0; i < n; i++) {
            if (S[i] == T[0]) {
                if (T.size() == 1) return T;
                int index = i + 1;
                if (index >= n) break; // didn't find and won't find more
                for (int j = 1; j < T.size(); j++) {
                    index = next[index][T[j] - 'a'];
                    if (index == -1) break;
                    index++;
                }
                if (index != -1 && index - i < mn) {
                    mn = index - i;
                    res = S.substr(i, index - i);
                }
            }
        }
        return res;
    }
};