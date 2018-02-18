class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        int res = n;
        vector<int> roots(n, -1);
        for (auto& e : edges) {
            int root1 = findRoot(roots, e.first);
            int root2 = findRoot(roots, e.second);
            if (root1 != root2) {
                res--;
                roots[root1] = root2;
            }
        }
        return res;
    }
    int findRoot(vector<int>& roots, int i) {
        while (roots[i] != -1) i = roots[i];
        return i;
    }
};