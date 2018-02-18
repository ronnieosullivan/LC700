class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res;
        unordered_map<char, int> m;
        unordered_set<char> st;
        for (char c : s) m[c]++;
        for (char c : s) {
            m[c]--;
            if (st.count(c)) continue;
            while (!res.empty() && res.back() > c && m[res.back()] > 0) {
                st.erase(res.back());
                res.pop_back();
            }
            res.push_back(c);
            st.insert(c);
        }
        return res;
    }
};