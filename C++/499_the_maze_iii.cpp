class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size(), n = maze[0].size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<string> strs = {"u", "d", "l", "r"};
        vector<vector<pair<int, string>>> dp(m, vector<pair<int, string>>(n, {INT_MAX, ""}));
        dp[ball[0]][ball[1]] = {0, ""};
        q.push({ball[0], ball[1]});
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second; q.pop();
            if (x == hole[0] && y == hole[1]) continue;
            for (int i = 0; i < 4; i++) {
                auto dir = dirs[i];
                int a = x, b = y, d = 0;
                while (a >= 0 && a < m && b >= 0 && b < n && maze[a][b] == 0 && (a != hole[0] || b != hole[1])) {
                    a += dir.first; b += dir.second; d++;
                }
                if (a != hole[0] || b != hole[1]) {
                    a -= dir.first; b -= dir.second; d--;
                }
                if (dp[a][b].first > dp[x][y].first + d) {
                    dp[a][b] = {dp[x][y].first + d, dp[x][y].second + strs[i]};
                    if (a != hole[0] || b != hole[1]) q.push({a, b});
                }
                else if (dp[a][b].first == dp[x][y].first + d && dp[a][b].second > dp[x][y].second + strs[i]) {
                    dp[a][b].second = dp[x][y].second + strs[i];
                    if (a != hole[0] || b != hole[1]) q.push({a, b});
                }
            }
        }
        return dp[hole[0]][hole[1]].first == INT_MAX ? "impossible" : dp[hole[0]][hole[1]].second;
    }
};