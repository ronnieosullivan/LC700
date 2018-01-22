class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return -1;
        int m = grid.size(), n = grid[0].size(), val = 0, res = INT_MAX;
        vector<vector<int>> sum(m, vector<int>(n));
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    res = INT_MAX;
                    int level = 1;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        int size = q.size();
                        for (int s = 0; s < size; ++s) {
                            int a = q.front().first, b = q.front().second; q.pop();
                            for (auto dir : dirs) {
                                int x = a + dir.first, y = b + dir.second;
                                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == val) {
                                    --grid[x][y];
                                    sum[x][y] += level;
                                    q.push({x, y});
                                    res = min(res, sum[x][y]);
                                }
                            }
                        }
                        level++;
                    }
                    val--;
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};