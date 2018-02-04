class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> v(nums.begin(), nums.end());
        return solve(v);
    }
    bool solve(vector<double>& v) {
        if (v.empty()) return false;
        if (v.size() == 1) return abs(v[0] - 24.0) < 1e-6;
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v.size(); j++) {
                if (i == j) continue;
                vector<double> v2;
                for (int k = 0; k < v.size(); k++) {
                    if (i != k && j != k) v2.push_back(v[k]);
                }
                for (int k = 0; k < 4; k++) {
                    if (k < 2 && j > i) continue;
                    if (k == 0) v2.push_back(v[i] + v[j]);
                    if (k == 1) v2.push_back(v[i] * v[j]);
                    if (k == 2) v2.push_back(v[i] - v[j]);
                    if (k == 3) {
                        if (v[j] != 0) {
                            v2.push_back(v[i] / v[j]);
                        } else {
                            continue;
                        }
                    }
                    if (solve(v2)) return true;
                    v2.pop_back();
                }
            }
        }
        return false;
    }
};