// Solution 1: 
// merge sort
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int res = 0;
        mergeSort(nums, 0, nums.size() - 1, res);
        return res;
    }
    void mergeSort(vector<int>& nums, int l, int r, int& res) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        mergeSort(nums, l, mid, res);
        mergeSort(nums, mid + 1, r, res);
        int i = l, j = mid + 1;
        while (i <= mid) {
            while (j <= r && nums[i] > 2 * (long long)nums[j]) j++;
            res += j - mid - 1;
            i++;
        }
        inplace_merge(nums.begin() + l, nums.begin() + mid + 1, nums.begin() + r + 1);
    }
};