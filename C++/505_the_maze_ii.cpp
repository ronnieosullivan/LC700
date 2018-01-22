class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[start[0]][start[1]] = 0;
        q.push({start[0], start[1]});
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second; q.pop();
            if (x == destination[0] && y == destination[1]) continue;
            for (auto dir : dirs) {
                int a = x, b = y, d = 0;
                while (a >= 0 && a < m && b >= 0 && b < n && maze[a][b] != 1) {
                    a += dir.first; b += dir.second;
                    d++;
                }
                a -= dir.first; b -= dir.second; d--;
                if (dp[a][b] > dp[x][y] + d) {
                    dp[a][b] = dp[x][y] + d;
                    q.push({a, b});
                }
            }
        }
        return dp[destination[0]][destination[1]] == INT_MAX ? -1 : dp[destination[0]][destination[1]];
    }
};