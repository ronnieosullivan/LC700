class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if (arr.empty()) return 0;
        int start = 0, target = 0, mx = INT_MIN, mn = INT_MAX, res = 0;
        for (int i = 0; i < arr.size(); i++) {
            mx = max(mx, arr[i]);
            mn = min(mn, arr[i]);
            if (mn == target && mx - mn == i - start) {
                res++;
                start = i + 1;
                target = i + 1;
                mx = INT_MIN;
                mn = INT_MAX;
            }
        }
        return res;
    }
};