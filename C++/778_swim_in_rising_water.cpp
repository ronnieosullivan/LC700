class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int mx = INT_MIN, mn = INT_MAX;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mx = max(mx, grid[i][j]);
            }
        }
        mn = grid[0][0];
        while (mn < mx) {
            int mid = mn + (mx - mn) / 2;
            if (canFinish(grid, mid)) {
                mx = mid;
            }
            else {
                mn = mid + 1;
            }
        }
        return mn;
    }
    bool canFinish(vector<vector<int>>& grid, int target) {
        if (grid[0][0] > target) return false;
        stack<pair<int, int>> st;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        st.push({0, 0});
        while (!st.empty()) {
            auto cur = st.top(); st.pop();
            if (cur.first == m - 1 && cur.second == n - 1) return true;
            visited[cur.first][cur.second] = true;
            for (auto dir : dirs) {
                int x = cur.first + dir.first, y = cur.second + dir.second;
                if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || grid[x][y] > target) continue;
                st.push({x, y});
            }
        }
        return false;
    }
};