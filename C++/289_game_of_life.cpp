// Solution 1:
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = m ? board[0].size() : 0;
        int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = 0;
                for (int k = 0; k < 8; ++k) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= 0 && x < m && y >= 0 && y < n && (board[x][y] == 1 || board[x][y] == 2)) {
                        ++cnt;
                    }
                }
                if (board[i][j] && (cnt < 2 || cnt > 3)) board[i][j] = 2;
                else if (!board[i][j] && cnt == 3) board[i][j] = 3;
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] %= 2;
            }
        }
    }
};

// Solution 2:
// if board is vector<vector<bool>> that doesn't allow additional value
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = m ? board[0].size() : 0;
        int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        vector<vector<int>> tmp(2, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            tmp[i % 2] = board[i];
            for (int j = 0; j < n; ++j) {
                int cnt = 0;
                for (int k = 0; k < 8; ++k) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        if (dx[k] == -1) {
                            if (tmp[x % 2][y] == 1) {
                                cnt++;
                            }
                        }
                        else if (dx[k] == 0) {
                            if (tmp[x % 2][y] == 1) {
                                cnt++;
                            }
                        }
                        else if (board[x][y] == 1) ++cnt;
                    }
                }
                if (board[i][j] && (cnt < 2 || cnt > 3)) board[i][j] = 0;
                else if (!board[i][j] && cnt == 3) board[i][j] = 1;
            }
        }
    }
};

// What we learned:
// vector<T> assignment requires the assigner and assignee to have the same length.