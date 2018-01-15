class Solution {
public:
    string decodeString(string s) {
        string t = "";
        stack<int> counts;
        stack<string> strings;
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                cnt = cnt * 10 + (s[i] - '0');
            }
            else if (s[i] == '[') {
                counts.push(cnt);
                strings.push(t);
                cnt = 0; t.clear();
            }
            else if (s[i] == ']') {
                int k = counts.top(); counts.pop();
                for (int j = 0; j < k; ++j) strings.top() += t;
                t = strings.top(); strings.pop();
            }
            else {
                t += s[i];
            }
        }
        return strings.empty() ? t : strings.top();
    }
};