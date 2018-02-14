class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        map<pair<char, char>, unordered_set<char>> m;
        for (auto& a : allowed) {
            m[{a[0], a[1]}].insert(a[2]);
        }
        return dfs("", 0, bottom, m);
    }
    bool dfs(string cur, int index, string bottom, map<pair<char, char>, unordered_set<char>>& m) {
        int n = bottom.size();
        if (n == 1) return true;
        if (index >= n - 1) {
            return dfs("", 0, cur, m);
        }
        auto it = m.find({bottom[index], bottom[index + 1]});
        if (it == m.end()) return false;
        for (auto c : it->second) {
            cur.push_back(c);
            if (dfs(cur, index + 1, bottom, m)) return true;
            cur.pop_back();
        }
        return false;
    }
};