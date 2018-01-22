class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<256> st;
        for (auto a : s) {
            st.flip(a);
        }
        return st.count() < 2;
    }
};