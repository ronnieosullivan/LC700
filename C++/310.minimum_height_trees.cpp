class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) return {0};
        vector<int> res;
        vector<unordered_set<int>> g(n);
        queue<int> q;
        for (auto edge : edges) {
            g[edge.first].insert(edge.second);
            g[edge.second].insert(edge.first);
        }
        for (int i = 0; i < n; ++i) {
            if (g[i].size() == 1) q.push(i);
        }
        while (n > 2) {
            int size = q.size();
            n -= size;
            for (int i = 0; i < size; ++i) {
                int t = q.front(); q.pop();
                for (auto a : g[t]) {
                    g[a].erase(t);
                    if (g[a].size() == 1) q.push(a);
                }
            }
        }
        while (!q.empty()) {
            res.push_back(q.front()); q.pop();
        }
        return res;
    }
};