// Solution 1:
// binary search
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double mx = INT_MIN, mn = INT_MAX;
        for (int a : nums) {
            mx = max(mx, (double)a);
            mn = min(mn, (double)a);
        }
        while (mx - mn > 0.00001) {
            double mid = (mx + mn) / 2.0;
            cout << mid << endl;
            if (check(nums, k, mid)) {
                mn = mid;
            }
            else {
                mx = mid;
            }
        }
        return mn;
    }
    bool check(vector<int>& nums, int k, double mid) {
        double sum = 0, prev = 0, minSum = 0;
        for (int i = 0; i < k; i++) sum += nums[i] - mid;
        if (sum >= 0) return true;
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - mid;
            prev += nums[i - k] - mid;
            minSum = min(prev, minSum);
            if (sum >= minSum) return true;
        }
        return false;
    }
};