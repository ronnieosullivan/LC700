class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<vector<bool>> g(26, vector<bool>(26, false));
        bitset<26> dict;
        vector<int> ins(26, 0);
        queue<char> q;
        string res = "";
        for (auto word : words) {
            for (char a : word) {
                dict.set(a - 'a');
            }
        }
        for (int i = 1; i < words.size(); ++i) {
            int len = min(words[i].size(), words[i - 1].size()), j = 0;
            for (; j < len; j++) {
                if (words[i][j] != words[i - 1][j]) {
                    cout << words[i - 1][j] << "->" << words[i][j] << endl;
                    g[words[i - 1][j] - 'a'][words[i][j] - 'a'] = true;
                    break;
                }
            }
            if (j == len && words[i].size() < words[i - 1].size()) return "";
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (g[i][j]) ins[j]++;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (dict[i] && ins[i] == 0) {
                q.push('a' + i);
                res += 'a' + i;
            }
        }
        cout << q.size() << endl;
        while (!q.empty()) {
            char c = q.front(); q.pop();
            for (int i = 0; i < 26; i++) {
                if (g[c - 'a'][i]) {
                    --ins[i];
                    if (ins[i] == 0) {
                        q.push('a' + i);
                        res += 'a' + i;
                    }
                }
            }
        }
        cout << res << endl;
        return res.size() == dict.count() ? res : "";
    }
};