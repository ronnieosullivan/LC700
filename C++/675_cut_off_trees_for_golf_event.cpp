class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        vector<pair<int, int>> v;
        int m = forest.size(), n = forest[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] > 1) v.push_back({i, j});
            }
        }
        sort(v.begin(), v.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
            return forest[a.first][a.second] < forest[b.first][b.second];
        });
        int res = 0, x = 0, y = 0;
        for (auto a : v) {
            int tmp = bfs(forest, x, y, a.first, a.second);
            if (tmp == INT_MAX) return -1;
            res += tmp;
            x = a.first;
            y = a.second;
        }
        return res;
    }
    int bfs(vector<vector<int>>& forest, int x, int y, int i, int j) {
        int m = forest.size(), n = forest[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        q.push({x, y});
        int steps = 0;
        while (!q.empty()) {
            int cnt = q.size();
            while (cnt--) {
                auto node = q.front(); q.pop();
                if (node.first == i && node.second == j) return steps;
                for (auto dir : dirs) {
                    int newX = dir[0] + node.first, newY = dir[1] + node.second;
                    if (newX < 0 || newX >= m || newY < 0 || newY >= n || visited[newX][newY] || forest[newX][newY] == 0) continue;
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
            steps++;
        }
        return INT_MAX;
    }
};