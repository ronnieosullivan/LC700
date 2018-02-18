class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = accumulate(nums.begin(), nums.begin() + k, 0), res = sum;
        for (int i = k; i < nums.size(); ++i) {
            sum += nums[i] - nums[i - k];
            res = max(res, sum);
        }
        return res / k;
    }
};

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = -10000.0;
        double sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (i - k >= -1) {
                if (i - k >= 0) sum -= nums[i - k];
                res = max(res, sum / k);
            }
        }
        return res;
    }
};