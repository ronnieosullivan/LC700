class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0], mn = nums[n - 1], start = -1, end = -2;
        for (int i = 1; i < n; i++) {
            mx = max(mx, nums[i]);
            if (mx > nums[i]) end = i;
        }
        for (int i = n - 1; i >= 0; i--) {
            mn = min(mn, nums[i]);
            if (mn < nums[i]) start = i;
        }
        return end - start + 1;
    }
};