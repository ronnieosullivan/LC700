class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, int> roots;
        for (auto edge : edges) {
            int x = find(roots, edge[0]), y = find(roots, edge[1]);
            if (x == y) return edge;
            roots[x] = y;
        }
        return {};
    }
    int find(unordered_map<int, int>& roots, int i) {
        for (;;) {
            auto it = roots.find(i);
            if (it == roots.end()) break;
            else i = it->second;
        }
        return i;
    }
};