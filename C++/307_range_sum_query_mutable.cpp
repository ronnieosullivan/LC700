// Fenwick tree
class NumArray {
public:
    NumArray(vector<int> nums)
    : _nums(nums.size() + 1)
    , _bits(nums.size() + 1) {
        for (int i = 0; i < nums.size(); ++i) {
            update(i, nums[i]);
        }
    }
    
    void update(int i, int val) {
        int diff = val - _nums[i + 1];
        for (int j = i + 1; j < _bits.size(); j += (j&-j)) {
            _bits[j] += diff;
        }
        _nums[i + 1] = val;
    }
    
    int sumRange(int i, int j) {
        return getSum(j) - getSum(i - 1);
    }

    int getSum(int i) {
        int res = 0;
        for (int j = i + 1; j > 0; j -= (j&-j)) {
            res += _bits[j];
        }
        return res;
    }
private:
    vector<int> _nums;
    vector<int> _bits;
};

// Segment tree
class NumArray {
public:
    struct Node {
        int start;
        int end;
        int sum;
        Node* left;
        Node* right;
        Node(int start, int end): start(start), end(end), sum(0), left(nullptr), right(nullptr) {}
    };
    NumArray(vector<int> nums) {
        _nums = nums;
        _root = build(_nums, 0, _nums.size() - 1);
    }
    
    Node* build(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr;
        Node* node = new Node(start, end);
        if (start < end) {
            node->left = build(nums, start, (start + end) / 2);
            node->right = build(nums, (start + end) / 2 + 1, end);
            node->sum = node->left->sum + node->right->sum;
        }
        else node->sum = nums[start];
        return node;
    }
    
    void update(int i, int val) {
        int diff = val - _nums[i];
        _nums[i] = val;
        update(_root, i, diff);
    }
    
    void update(Node* node, int i, int diff) {
        if (!node || i < node->start || i > node->end) return;
        node->sum += diff;
        update(node->left, i, diff);
        update(node->right, i, diff);
    }
    
    int sumRange(int i, int j) {
        return getSum(_root, i, j);
    }
    
    int getSum(Node* node, int i, int j) {
        if (!node || j < node->start || i > node->end) return 0;
        if (i <= node->start && j >= node->end) return node->sum;
        return getSum(node->left, i, j) + getSum(node->right, i, j);
    }
private:
    Node* _root;
    vector<int> _nums;
};