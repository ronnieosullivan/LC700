class Solution {
public:
    vector<int> findPermutation(string s) {
        int n = s.size();
        vector<int> res(n + 1);
        for (int i = 0; i < res.size(); i++) {
            res[i] = i + 1;
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == 'D') {
                int j = i + 1;
                while (j < n && s[j] == 'D') j++;
                reverse(res.begin() + i, res.begin() + j + 1);
                i = j - 1;
            }
        }
        return res;
    }
};