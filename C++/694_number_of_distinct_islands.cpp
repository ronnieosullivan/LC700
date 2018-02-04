class Solution {
public:
    using Island = vector<pair<int ,int>>;
    vector<pair<int, int>> dirs {{0,-1},{-1,0},{0,1},{1,0}};
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<Island> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    Island island;
                    dfs(grid, i, j, i, j, island);
                    res.insert(island);
                }
            }
        }
        return res.size();
    }
    void dfs(vector<vector<int>>& grid, int x, int y, int i, int j, Island& island) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) return;
        grid[i][j] = -1;
        island.push_back({i - x, j - y});
        for (auto dir : dirs) {
            dfs(grid, x, y, i + dir.first, j + dir.second, island);
        }
    }
};