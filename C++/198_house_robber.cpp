class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0, b = 0;
        for (auto num : nums) {
            int t = a;
            a = max(a, b);
            b = t + num;
        }
        return max(a, b);
    }
};