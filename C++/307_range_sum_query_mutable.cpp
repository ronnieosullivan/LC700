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