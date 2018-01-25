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

// Solution 2:
// bit
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int res = 0;
        vector<int> copy = nums;
        vector<int> bits(nums.size() + 1);
        sort(copy.begin(), copy.end());
        for (int a : nums) {
            res += search(bits, index(copy, 2 * (long long)a + 1));
            insert(bits, index(copy, a));
        }
        return res;
    }
    int index(vector<int>& copy, long long val) {
        int l = 0, r = copy.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (copy[mid] >= val) r = mid - 1;
            else l = mid + 1;
        }
        return l + 1;
    }
    int search(vector<int>& bits, int i) {
        int res = 0;
        for (; i < bits.size(); i += (i&-i)) {
            res += bits[i];
        }
        return res;
    }
    void insert(vector<int>& bits, int i) {
        for (; i > 0; i -= (i&-i)) {
            bits[i] += 1;
        }
    }
};