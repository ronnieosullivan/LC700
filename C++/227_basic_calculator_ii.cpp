class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int t = 0, res = 0; char sign = '+';
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                t = t * 10 + s[i] - '0';
            }
            if ((s[i] < '0' && s[i] != ' ') || i == s.size() - 1) {
                if (sign == '+') st.push(t);
                else if (sign == '-') st.push(-t);
                else if (sign == '*' || sign == '/') {
                    int tmp = sign == '*' ? st.top() * t : st.top() / t;
                    st.pop();
                    st.push(tmp);
                }
                sign = s[i];
                t = 0;
            }
        }
        while (!st.empty()) {
            res += st.top(); st.pop();
        }
        return res;
    }
};