class Solution {
public:
    string findContestMatch(int n) {
        vector<string> res(n, "");
        for (int i = 0; i < n; i++) {
            res[i] = to_string(i + 1);
        }
        int cnt = n;
        while (cnt != 1) {
            for (int i = 0; i < cnt / 2; i++) {
                res[i] = "(" + res[i] + "," + res[cnt - i - 1] + ")";
            }
            cnt /= 2;
        }
        return res[0];
    }
};