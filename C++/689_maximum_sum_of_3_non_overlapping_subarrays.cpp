class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n + 1), posLeft(n), posRight(n), res(3);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
        // left start from 0 to n-k to get max sum left interval values
        for (int i = k, total = sum[k] - sum[0]; i < n; i++){
            if (sum[i + 1] - sum[i - k + 1] > total) {
                total = sum[i + 1] - sum[i - k + 1];
                posLeft[i] = i - k + 1;
            } else {
                posLeft[i] = posLeft[i - 1];
            }
        }
        
        // right start from 0 to n-k to get max sum right interval values
        posRight[n - k] = n - k;
        for (int i = n - k - 1, total = sum[n] - sum[n - k]; i >= 0; i--) {
            if (sum[k + i] - sum[i] > total) {
                total = sum[k + i] - sum[i];
                posRight[i] = i;
            } else {
                posRight[i] = posRight[i + 1];
            }
        }
        
        // test all middle interval
        int maxsum = 0;
        for (int i = k; i <= n - 2 * k; i++) {
            int l = posLeft[i - 1], r = posRight[i + k];
            int total = (sum[i + k] - sum[i]) + (sum[l + k] - sum[l]) + (sum[r + k] - sum[r]);
            if (total > maxsum) {
                maxsum = total;
                res[0] = l; res[1]= i; res[2] = r;
            }
        }
        return res;
    }
};