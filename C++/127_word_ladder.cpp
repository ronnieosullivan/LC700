class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int level = 2;
        while (!q.empty()) {
            int cnt = q.size();
            for (int i = 0; i < cnt; i++) {
                string word = q.front(); q.pop();
                for (int j = 0; j < word.size(); ++j) {
                    string copy = word;
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        copy[j] = ch;
                        if (dict.count(copy)) {
                            if (copy == endWord) return level;
                            q.push(copy);
                            dict.erase(copy);
                        }
                    }
                }
            }
            level++;
        }
        return 0;
    }
};