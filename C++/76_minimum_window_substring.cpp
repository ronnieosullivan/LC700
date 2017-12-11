// Solution 1:
// sliding window
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        string res = "";
        int left = 0, count = 0, minLen = s.size() + 1;
        vector<int> tm(256), sm(256);
        for (int i = 0; i < t.size(); ++i) ++tm[t[i]];
        for (int right = 0; right < s.size(); ++right) {
            char c = s[right];
            if (tm[c] != 0) {
                ++sm[c];
                if (sm[c] <= tm[c]) ++count;
                while (count == t.size()) {
                    if (right - left + 1 < minLen) {
                        minLen = right - left + 1;
                        res = s.substr(left, minLen);
                    }
                    if (tm[s[left]] != 0) {
                        --sm[s[left]];
                        if (sm[s[left]] < tm[s[left]]) --count;
                    }
                    ++left;
                }
            }
        }
        return res;
    }
};