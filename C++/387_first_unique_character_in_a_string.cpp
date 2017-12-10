class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> v(128);
        for (char c : s) ++v[c];
        for (int i = 0; i < s.size(); ++i) {
            if (v[s[i]] == 1) return i;
        }
        return -1;
    }
};