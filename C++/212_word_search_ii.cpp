class Solution {
public:
    struct TrieNode {
        vector<TrieNode*> children;
        string str;
        TrieNode()
        : children(26, nullptr)
        , str("") {}
    };
    void insert(TrieNode* root, const string& word) {
        TrieNode* p = root;
        for (char c : word) {
            if (!p->children[c - 'a']) p->children[c - 'a'] = new TrieNode();
            p = p->children[c - 'a'];
        }
        p->str = word;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (board.empty() || board[0].empty()) return res;
        int m = board.size(), n = board[0].size();
        TrieNode* root = new TrieNode();
        for (const auto& word : words) insert(root, word);
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                search(board, root, i, j, visited, res);
            }
        }
        return res;
    }
    void search(const vector<vector<char>>& board, TrieNode* p, int i, int j, vector<vector<bool>>& visited, vector<string>& res) {
        if (!p->children[board[i][j] - 'a']) return;
        if (!p->children[board[i][j] - 'a']->str.empty()) {
            res.push_back(p->children[board[i][j] - 'a']->str);
            p->children[board[i][j] - 'a']->str.clear(); // avoid dup in result
        }
        int m = board.size(), n = board[0].size();
        visited[i][j] = true;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (const auto& dir : dirs) {
            int x = dir.first + i, y = dir.second + j;
            if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]) {
                search(board, p->children[board[i][j] - 'a'], x, y, visited, res);
            }
        }
        visited[i][j] = false;
    }
};