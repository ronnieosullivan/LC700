class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size(), mn = INT_MAX, mx = INT_MIN, res = 0;
        vector<int> minArr(n, INT_MAX);
        for (int i = n - 1; i > 0; i--) {
            mn = min(mn, arr[i]);
            minArr[i - 1] = mn;
        }
        for (int i = 0; i < n; i++) {
            mx = max(arr[i], mx);
            if (mx <= minArr[i]) {
                res++;
                mx = INT_MIN;
            }
        }
        return res;
    }
};