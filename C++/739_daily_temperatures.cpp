// preferred:
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[st.top()]< temperatures[i]) {
                res[st.top()] = i - st.top(); st.pop();
            }
            st.push(i);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        map<int, int> m;
        int n = temperatures.size();
        vector<int> res(n, INT_MAX);
        for (int i = n - 1; i >= 0; i--) {
            auto it = m.upper_bound(temperatures[i]);
            while (it != m.end()) {
                res[i] = min(res[i], it->second - i);
                it++;
            }
            if (res[i] == INT_MAX) res[i] = 0;
            m[temperatures[i]] = i;
        }
        return res;
    }
};