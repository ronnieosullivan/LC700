// Solution 1:
// binary search
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int r = nums.back() - nums.front();
        while (l <= r) {
            int cnt = 0;
            int j = 0;
            int mid = l + (r - l) / 2;
            for (int i = 0; i < n; ++i) {
                while (j < n && nums[j] - nums[i] <= mid) ++j;
                cnt += j - i - 1;
            }
            cnt >= k ? r = mid - 1 : l = mid + 1;
        }        
        return l;
    }
};

// Solution 2:
// LTS!! as the range can be too large
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int mx = INT_MIN, mn = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);
        }
        int cnt = 0;
        for (int diff = 0; diff <= mx - mn; ++diff) {
            for (auto a : m) {
                if (diff == 0) {
                    cnt += a.second * (a.second - 1) / 2;
                }
                else if (m.count(a.first - diff)) {
                    cnt += a.second * m[a.first - diff];
                }
            }
            if (cnt >= k) return diff;
        }
        return -1;
    }
};

// Idea from solution 2 can be merged into solution 1:
// Accepted
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int r = nums.back() - nums.front();
        while (l <= r) {
            int cnt = 0;
            int j = 0;
            int mid = l + (r - l) / 2;
            for (int i = 0; i < n; ++i) {
                while (j < n && nums[j] - nums[i] <= mid) j += m[nums[j]];
                cnt += j - i - 1;
            }
            cnt >= k ? r = mid - 1 : l = mid + 1;
        }        
        return l;
    }
};