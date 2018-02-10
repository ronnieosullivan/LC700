class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> v(length + 1);
        for (auto& u : updates) {
            v[u[0]] += u[2];
            v[u[1] + 1] -= u[2];
        }
        int cur = 0;
        for (int i = 0; i <= length; i++) {
            cur += v[i];
            v[i] = cur;
        }
        v.pop_back();
        return v;
    }
};