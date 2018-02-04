class Solution {
public:
    using Island = vector<pair<int ,int>>;
    vector<pair<int, int>> dirs {{0,-1},{-1,0},{0,1},{1,0}};
    int numDistinctIslands2(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<Island> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    Island island;
                    dfs(grid, i, j, island);
                    auto normal = norm(island);
                    res.insert(normal);
                }
            }
        }
        return res.size();
    }
    void dfs(vector<vector<int>>& grid, int i, int j, Island& island) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) return;
        grid[i][j] = -1;
        island.push_back({i, j});
        for (auto dir : dirs) {
            dfs(grid, i + dir.first, j + dir.second, island);
        }
    }
    Island norm(Island& origin) {
        vector<Island> rotationsAndRelfections(8);
        vector<pair<int, int>> topLeft(8);
        for (auto point : origin) {
            int x = point.first, y = point.second;
            rotationsAndRelfections[0].emplace_back(x, y);
            rotationsAndRelfections[1].emplace_back(x, -y);
            rotationsAndRelfections[2].emplace_back(-x, y);
            rotationsAndRelfections[3].emplace_back(-x, -y);
            rotationsAndRelfections[4].emplace_back(y, x);
            rotationsAndRelfections[5].emplace_back(-y, x);
            rotationsAndRelfections[6].emplace_back(y, -x);
            rotationsAndRelfections[7].emplace_back(-y, -x);
        }
        for (auto& r : rotationsAndRelfections) {
            sort(r.begin(), r.end());
        }
        for (auto& island : rotationsAndRelfections) {
            for (int i = 1; i < origin.size(); ++i) {
                island[i].first -= island[0].first;
                island[i].second -= island[0].second;
            }
            island[0] = {0, 0};
        }
        return *min_element(rotationsAndRelfections.begin(), rotationsAndRelfections.end());
    }
};