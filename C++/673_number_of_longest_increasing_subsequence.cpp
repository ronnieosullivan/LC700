// Solution 1:
// Time: O(n^2)
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int res = 0, mx = 0, n = nums.size();
        vector<int> len(n, 1), cnt(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] <= nums[j]) continue;
                if (len[i] == len[j] + 1) cnt[i] += cnt[j];
                else if (len[i] < len[j] + 1) {
                    len[i] = len[j] + 1;
                    cnt[i] = cnt[j];
                }
            }
            if (mx == len[i]) res += cnt[i];
            else if (mx < len[i]) {
                mx = len[i];
                res = cnt[i];
            }
        }
        return res;
    }
};

// Solution 2:
// Time: O(n^2)
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int res = 0, mx = 0, n = nums.size();
        vector<int> len(n, 1), cnt(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] <= nums[j]) continue;
                if (len[i] == len[j] + 1) cnt[i] += cnt[j];
                else if (len[i] < len[j] + 1) {
                    len[i] = len[j] + 1;
                    cnt[i] = cnt[j];
                }
            }
            mx = max(mx, len[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (mx == len[i]) res += cnt[i];
        }
        return res;
    }
};

// Solution 3:
// segment tree
// Time: O(nlogn), space: O(n)
