class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> v(26);
        for (char c : licensePlate) {
            if (c >= 'a' && c <= 'z') v[c - 'a']++;
            else if (c >= 'A' && c <= 'Z') v[c - 'A']++;
        }
        string res;
        for (auto& s : words) {
            if (isValid(s, v)) {
                if (res.empty() || s.size() < res.size()) res = s;
            }
        }
        return res;
    }
    bool isValid(string s, vector<int> v) {
        vector<int> t(26);
        for (char c : s) {
            t[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (t[i] < v[i]) return false;
        }
        return true;
    }
};