class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        if (n % 2) return findKth(nums1, 0, nums2, 0, n / 2 + 1);
        else return (findKth(nums1, 0, nums2, 0, n / 2) + findKth(nums1, 0, nums2, 0, n / 2 + 1)) / 2;
    }
    double findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        int m = nums1.size(), n = nums2.size();
        if (m == i) return nums2[j + k - 1];
        if (n == j) return nums1[i + k - 1];
        if (k == 1) return min(nums1[i], nums2[j]);
        int x = min(m, i + k / 2), y = min(n, j + k / 2);
        if (nums1[x - 1] < nums2[y - 1]) {
            return findKth(nums1, x, nums2, j, k - x + i);
        } else {
            return findKth(nums1, i, nums2, y, k - y + j);
        }
    }
};