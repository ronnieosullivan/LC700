// Solution 1:
// O(log n)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] > arr[mid + k] - x) left = mid + 1;
            else right = mid;
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};

// Solution 2:
// O(n)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        int n = arr.size();
        int mid = 0;
        for (int i = 1; i < n; i++) {
            if (abs(arr[i] - x) < abs(arr[mid] - x)) mid = i;
        }
        int left = mid - 1, right = mid + 1;
        while (k > 1) {
            if (left < 0) right++;
            else if (right >= n) left--;
            else if (abs(arr[left] - x) <= abs(arr[right] - x)) {
                left--;
            }
            else right++;
            k--;
        }
        for (int i = left + 1; i < right; i++) res.push_back(arr[i]);
        return res;
    }
};