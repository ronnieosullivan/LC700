class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), [](const string& a, const string& b){
            return a.length() == b.length() ? a < b : a.length() > b.length();
        });
        for (auto& a : d) {
            if (canBeSameByDeleting(s, a)) return a;
        }
        return "";
    }
    bool canBeSameByDeleting(const string& s, const string& target) {
        int m = s.size(), n = target.size(), i = 0, j = 0;
        while (i < m && j < n) {
            if (s[i] == target[j]) { i++; j++; }
            else i++;
        }
        return j == n;
    }
};