class Solution {
public:
    int calculate(string s) {
        unordered_map<int, int> m;
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(i);
            else if (s[i] == ')') {
                m[st.top()] = i; st.pop();
            }
        }
        return helper(s, 0, s.size(), m);
    }
    int helper(string& s, int start, int end, unordered_map<int, int>& m) {
        stack<int> st;
        int t = 0, res = 0; char sign = '+';
        for (int i = start; i < end; i++) {
            if (s[i] == '(') {
                t = helper(s, i + 1, m[i], m);
                i = m[i];
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                t = t * 10 + s[i] - '0';
            }
            if ((s[i] < '0' && s[i] != ' ') || i == end - 1) {
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