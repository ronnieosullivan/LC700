class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        long long l = lower;
        for (int i = 0; i <= nums.size(); ++i) {
            long long r = (i < nums.size() && nums[i] <= upper) ? nums[i] : (long long)upper + 1;
            if (l == r) ++l;
            else if (r > l) {
                res.push_back(toString(l, r));
                l = r + 1;
            }
        }
        return res;
    }
    string toString(long long l, long long r) {
        return r - l == 1 ? to_string(l) : to_string(l) + "->" + to_string(r - 1);
    }
};