class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        q.push({start[0], start[1]});
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second; q.pop();
            if (x == destination[0] && y == destination[1]) return true;
            maze[x][y] = -1;
            for (auto dir : dirs) {
                int a = x, b = y;
                while (a >= 0 && a < m && b >= 0 && b < n && maze[a][b] != 1) {
                    a += dir.first; b += dir.second;
                }
                a -= dir.first; b -= dir.second;
                if (maze[a][b] != -1) q.push({a, b});
            }
        }
        return false;
    }
};
