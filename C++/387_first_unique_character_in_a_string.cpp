// Solution 1: one pass
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> v;
        vector<int> dict(26);
        for (int i = 0; i < s.length(); ++i) {
            dict[s[i] - 'a']++;
            if (dict[s[i] - 'a'] == 1) v.push_back(i);
        }
        for (int i : v) {
            if (dict[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};

// Solution 2: two pass
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