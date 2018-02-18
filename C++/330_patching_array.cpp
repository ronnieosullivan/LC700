class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int res = 0, i = 0;
        long long x = 1;
        while (x <= n) {
            if (i < nums.size() && nums[i] <= x) {
                x += nums[i++];
            } else {
                x *= 2;
                ++res;
            }
        }
        return res;
    }
};