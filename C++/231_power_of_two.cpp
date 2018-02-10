class Solution {
public:
    bool isPowerOfTwo(int n) {
        bitset<32> s = n;
        return n > 0 && s.count() == 1;
    }
};