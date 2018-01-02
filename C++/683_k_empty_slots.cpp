class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        if (flowers.empty()) return -1;
        int n = flowers.size();
        vector<int> bits(n + 2);
        for (int i = 0; i < n; i++) {
            int pos = flowers[i];
            update(bits, pos, 1);
            int left = pos - k - 1, right = pos + k + 1;
            if (left >= 1 && sumRange(bits, left, left) == 1 && sumRange(bits, left + 1, pos - 1) == 0) {
                return i + 1;
            }
            if (right <= n && sumRange(bits, right, right) == 1 && sumRange(bits, pos + 1, right - 1) == 0) {
                return i + 1;
            }
        }
        return -1;
    }
    int sumRange(vector<int>& bits, int i, int j) {
        return getSum(bits, j + 1) - getSum(bits, i);
    }
    int getSum(vector<int>& bits, int i) {
        int res = 0;
        for (int j = i; j > 0; j -= (j&-j)) {
            res += bits[j];
        }
        return res;
    }
    void update(vector<int>& bits, int i, int val) {
        int diff = val - getSum(bits, i + 1) + getSum(bits, i);
        for (int j = i + 1; j < bits.size(); j += (j&-j)) {
            bits[j] += diff;
        }
    }
};