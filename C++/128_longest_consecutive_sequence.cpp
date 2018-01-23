class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for (int num : nums) {
            if (!s.count(num)) continue;
            s.erase(num);
            int left = num - 1, right = num + 1;
            while (s.count(left)) s.erase(left--);
            while (s.count(right)) s.erase(right++);
            res = max(res, right - left - 1);
        }
        return res;
    }
};