class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int res = 0;
        vector<long long> v(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i) {
            v[i + 1] = v[i] + nums[i];
        }
        mergeSort(v, 0, v.size() - 1, lower, upper, res);
        return res;
    }
    void mergeSort(vector<long long>& v, int l, int r, int lower, int upper, int& res) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        mergeSort(v, l, mid, lower, upper, res);
        mergeSort(v, mid + 1, r, lower, upper, res);
        int i = l, j = mid + 1, k = mid + 1;
        while (i <= mid) {
            while (j <= r && v[j] - v[i] < lower) j++;
            while (k <= r && v[k] - v[i] <= upper) k++;
            if (k - j > 0) res += k - j;
            i++;
        }
        inplace_merge(v.begin() + l, v.begin() + mid + 1, v.begin() + r + 1);
    }
};