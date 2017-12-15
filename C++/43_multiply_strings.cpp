class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        vector<int> v(m + n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                v[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        int carry = 0;
        for (int i = m + n - 1; i >= 0; --i) {
            v[i] += carry;
            carry = v[i] / 10;
            v[i] %= 10;
        }
        int i = 0; string res = "";
        while (v[i] == 0 && i < m + n) ++i;
        if (i >= m + n) return "0";
        while (i < m + n) res.push_back(v[i++] + '0');
        return res;
    }
};