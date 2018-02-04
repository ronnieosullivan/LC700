class Solution {
public:
    int longestPalindrome(string s) {
        bitset<128> st;
        for (char c : s) st.flip(c);
        int cnt = st.count();
        return s.size() - cnt + (cnt ? 1 : 0);
    }
};