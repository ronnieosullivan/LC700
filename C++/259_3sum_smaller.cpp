class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            int sum = target - nums[i];
            int left = i + 1, right = n - 1;
            while (left < right) {
                while (left < right && nums[left] + nums[right] >= sum) right--;
                if (left < right) {
                    res += right - left;
                }
                left++;
            }
        }
        return res;
    }
};