// Solution 1:
// Time: O(nlogn)
// Space: O(n)
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> copy(nums);
        
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                nums[i] = copy[(n - 1) / 2 - i / 2];
            }
            else {
                nums[i] = copy[n - 1 - i / 2];
            }
        }
    }
};

// Solution 2:
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        #define A(i) nums[(1 + 2 * i) % (n | 1)]
        int n = nums.size(), i = 0, j = 0, k = n - 1;
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        while (j <= k) {
            if (A(j) > mid) swap(A(i++), A(j++));
            else if (A(j) < mid) swap(A(j), A(k--));
            else ++j;
        }
    }
};

// Solution 3:
// same as solution 2, but a self-implemented quickselect
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        #define A(i) nums[(1 + 2 * i) % (n | 1)]
        int n = nums.size(), left = 0, i = 0, right = n - 1;
        int mid = kthSmallest(nums, 0, n - 1, n / 2 + 1);
        cout << mid << endl;
        while (i <= right) {
            if (A(i) > mid) swap(A(left++), A(i++));
            else if (A(i) < mid) swap(A(i), A(right--));
            else ++i;
        }
    }
    int partition(vector<int>& nums, int l, int r) {
        int x = nums[r], i = l;
        for (int j = l; j < r; j++) {
            if (nums[j] <= x) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[r]);
        return i;
    }
    int kthSmallest(vector<int>& nums, int l, int r, int k) {
        if (k < 0 || k > r - l + 1) return INT_MAX;
        int index = partition(nums, l, r);
        if (index - l + 1 == k) return nums[index];
        else if (index - l + 1 > k) return kthSmallest(nums, l, index - 1, k);
        else return kthSmallest(nums, index + 1, r, k - index + l - 1);
    }
};