class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        string t = s;
        sort(t.begin(), t.end(), greater<int>());
        int n = s.size(), i = 0;
        for (; i < n; i++) {
            if (t[i] != s[i]) break;
        }
        int second = s.find_last_of(t[i]);
        swap(s[i], s[second]);
        return stoi(s);
    }
};