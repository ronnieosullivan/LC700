class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> roots(m * n, -1);
        vector<int> res;
        int cnt = 0;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto position : positions) {
            int cur = position.first * n + position.second;
            roots[cur] = cur;
            ++cnt;
            for (auto dir : dirs) {
                int x = dir.first + position.first, y = dir.second + position.second;
                if (x < 0 || x >= m || y < 0 || y >= n || roots[x * n + y] == -1) continue;
                int newRoot = getRoot(x * n + y, roots);
                if (newRoot != cur) {
                    roots[cur] = newRoot;
                    cur = newRoot;
                    cnt--;
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
    int getRoot(int i, vector<int>& roots) {
        if (roots[i] == -1) return i;
        while (i != roots[i]) {
            i = roots[i];
        }
        return i;
    }
};