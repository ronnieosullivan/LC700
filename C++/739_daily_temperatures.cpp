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