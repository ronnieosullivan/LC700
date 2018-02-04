class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        unordered_map<int, int> roots, parents;
        vector<int> cand1, cand2;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (parents.count(v)) {
                cand1 = { parents[v], v };
                cand2 = edge;
                edge[0] = -1; edge[1] = -1; // delete
                break;
            }
            parents[v] = u;
        }
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (u < 0 || v < 0) continue;
            int root1 = find(roots, u);
            int root2 = find(roots, v);
            if (root1 == root2) {
                return cand1.empty() ? edge : cand1;
            }
            roots[root1] = root2;
        }
        return cand2;
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