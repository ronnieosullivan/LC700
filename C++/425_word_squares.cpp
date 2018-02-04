class Solution {
public:
    struct TrieNode {
        TrieNode()
        : children(26, nullptr) {}
        vector<TrieNode*> children;
        vector<int> indexes; // words
    };
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (int i = 0; i < words.size(); ++i) {
            TrieNode* p = root;
            for (int j = 0; j < words[i].size(); ++j) {
                if (!p->children[words[i][j] - 'a']) p->children[words[i][j] - 'a'] = new TrieNode();
                p = p->children[words[i][j] - 'a'];
                p->indexes.push_back(i);
            }
        }
        return root;
    }
    vector<vector<string>> wordSquares(vector<string>& words) {
        TrieNode *root = buildTrie(words);
        vector<string> cur(words[0].size());
        vector<vector<string>> res;
        for (string word : words) {
            cur[0] = word;
            helper(words, 1, root, cur, res);
        }
        return res;
    }
    void helper(vector<string>& words, int level, TrieNode* root, vector<string>& cur, vector<vector<string>>& res) {
        if (level >= words[0].size()) {
            res.push_back(cur);
            return;
        }
        string prefix = "";
        for (int i = 0; i < level; ++i) {
            prefix += cur[i][level];
        }
        TrieNode *p = root;
        for (int i = 0; i < prefix.size(); ++i) {
            if (!p->children[prefix[i] - 'a']) return;
            p = p->children[prefix[i] - 'a'];
        }
        for (int idx : p->indexes) {
            cur[level] = words[idx];
            helper(words, level + 1, root, cur, res);
        }
    }
};