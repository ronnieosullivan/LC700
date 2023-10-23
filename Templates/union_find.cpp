vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    vector<int> root(2001), rank(2001);
    for (int i = 0; i < 2001; i++) {
        root[i] = i;
    }
    for (auto edge : edges) {
        int x = find(root, edge[0]), y = find(root, edge[1]);
        if (x == y) return edge;
        if (rank[x] > rank[y]) {
            root[y] = x;  // Attach smaller rank tree under root of larger rank tree
        } else if (rank[x] < rank[y]) {
            root[x] = y;
        } else {  // If ranks are same
            root[y] = x;
            rank[x]++;  // Increase the rank of the new root
        }
    }
    return {};
}

int find(vector<int>& root, int i) {
    if (root[i] != i) {
        root[i] = find(root, root[i]);
    }
    return root[i];
}
