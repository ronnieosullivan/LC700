class Solution {
public:
    int calculate(string s) {
        int cur = 0, sign = 1;
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(cur);
                st.push(sign);
                cur = 0;
                sign = 1;
            }
            else if (s[i] == ')') {
                cur *= st.top(); st.pop();
                cur += st.top(); st.pop();
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                int num = 0;
                while (i < s.size() && s[i] >= '0') {
                    num = 10 * num + s[i++] - '0';
                }
                cur += sign * num;
                --i;
            }
            else if (s[i] == '+') {
                sign = 1;
            }
            else if (s[i] == '-') {
                sign = -1;
            }
        }
        return cur;
    }
};