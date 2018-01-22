class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
        return max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size()));
    }
    int rob(vector<int> &nums, int left, int right) {
        int a = 0, b = 0;
        for (int i = left; i < right; ++i) {
            int t = a;
            a = max(a, b);
            b = t + nums[i];
        }
        return max(a, b);
    }
};