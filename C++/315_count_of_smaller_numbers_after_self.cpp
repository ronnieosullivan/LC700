// Solution 1: merge sort
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res (nums.size(), 0);
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); i++) {
            v.emplace_back(nums[i], i);
        }
        mergeSort(v, res, 0, nums.size() - 1);
        return res;
    }
    
    void mergeSort(vector<pair<int, int>>& v, vector<int>& res, int l, int r) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        mergeSort(v, res, l, mid); // [l, mid] sorted
        mergeSort(v, res, mid + 1, r); // [mid + 1, r] sorted
        int i = l, j = mid + 1;
        while (i <= mid) {
            while (j <= r && v[i] > v[j]) j++;
            res[v[i].second] += j - mid - 1;
            i++;
        }
        inplace_merge(v.begin() + l, v.begin() + mid + 1, v.begin() + r + 1);
    }
};

// Solution 2: binary search tree
// Time: O(nlogn), worst case O(n^2) ?
class Solution {
public:
    struct Node {
        int val, smaller;
        Node *left, *right;
        Node(int v, int s) : val(v), smaller(s), left(NULL), right(NULL) {}
    };
    int insert(Node *&root, int v) {
        if (!root) {
            root = new Node(v, 0);
            return 0;
        }
        if (root->val > v) {
            root->smaller++;
            return insert(root->left, v);
        }
        else {
            return insert(root->right, v) + root->smaller + (root->val < v ? 1 : 0);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());
        Node *root = NULL;
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] = insert(root, nums[i]);
        }
        return res;
    }
};