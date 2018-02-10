class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> roots(n, -1);
        for (auto a : edges) {
            int root1 = find(roots, a.first);
            int root2 = find(roots, a.second);
            if (root1 == root2) return false;
            roots[root1] = root2;
        }
        return edges.size() == n - 1;
    }
    int find(vector<int>& roots, int i) {
        while (roots[i] != -1) i = roots[i];
        return i;
    }
};