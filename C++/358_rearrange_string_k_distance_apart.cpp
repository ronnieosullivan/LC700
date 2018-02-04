class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k == 0) return s;
        string res;
        int n = s.size();
        vector<int> dict(26, 0);
        priority_queue<pair<int, char>> q;
        for (auto a : s) ++dict[a - 'a'];
        for (int i = 0; i < 26; i++) {
            if (dict[i] > 0) q.push({dict[i], 'a' + i});
        }
        while (!q.empty()) {
            vector<pair<int, int>> v;
            int cnt = min(k, n);
            for (int i = 0; i < cnt; i++) {
                if (q.empty()) return "";
                auto t = q.top(); q.pop();
                res.push_back(t.second);
                if (--t.first > 0) v.push_back(t);
                --n;
            }
            for (auto a : v) q.push(a);
        }
        return res;
    }
};