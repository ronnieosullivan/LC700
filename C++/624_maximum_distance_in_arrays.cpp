class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0, mn = arrays[0][0], mx = arrays[0].back();
        for (int i = 1; i < arrays.size(); ++i) {
            res = max(res, max(abs(arrays[i].back() - mn), abs(mx - arrays[i][0])));
            mn = min(mn, arrays[i][0]);
            mx = max(mx, arrays[i].back());
        }
        return res;
    }
};